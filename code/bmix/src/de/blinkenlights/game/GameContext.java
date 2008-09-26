/*
 * Created on Sep 25, 2008
 *
 * This code belongs to SQL Power Group Inc.
 */
package de.blinkenlights.game;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.FileInputStream;
import java.net.InetAddress;
import java.util.Properties;
import java.util.logging.Logger;

public class GameContext {

    Logger logger = Logger.getLogger(GameContext.class.getName());
    
    private final BlinkenGame game;
    
    /**
     * True when the game is already running.
     */
    private boolean gameRunning = false;

    private int playfieldWidth;

    private int playfieldHeight;
    
    private double framesPerSecond;

    private FrameTarget bmixClient;

    private UserInputSource inputClient;
    
    
    GameContext(BlinkenGame game) throws GameConfigurationException {
        this.game = game;
        readConfiguration();
    }

    /**
     * Reads the configuration from a properties file called
     * blinkengame.properties in the current directory.
     * 
     * @throws GameConfigurationException
     *             if the file "blinkengame.properties" is not in the current
     *             directory, it cannot be read, or it does not contain the
     *             required set of property values.
     */
    private void readConfiguration() throws GameConfigurationException {
        try {
            Properties config = new Properties();
            config.load(new FileInputStream("blinkengame.properties"));
            playfieldWidth = Integer.parseInt(config.getProperty("playfield.width"));
            playfieldHeight = Integer.parseInt(config.getProperty("playfield.height"));

            framesPerSecond = Double.parseDouble(config.getProperty("playfield.fps"));
            
            if (Boolean.valueOf(config.getProperty("bmix.simulate"))) {
                bmixClient = new OutputSimulator();
            } else {
                InetAddress bmixHost = InetAddress.getByName(config.getProperty("bmix.host"));
                int bmixPort = Integer.parseInt(config.getProperty("bmix.port"));
                bmixClient = new BMixClient(bmixHost, bmixPort);
            }
            
            if (Boolean.valueOf(config.getProperty("telephony.simulate"))) {
                inputClient = new TelephoneSimulator();
            } else {
                InetAddress bltHost = InetAddress.getByName(config.getProperty("telephony.host"));
                int bltPort = Integer.parseInt(config.getProperty("telephony.port"));
                String did = config.getProperty("telephony.did");
                inputClient = new BLTClient(bltHost, bltPort, did);
            }
            
        } catch (Exception ex) {
            throw new GameConfigurationException(ex);
        }
    }

    /**
     * Starts the game context, which causes it to register with the telephony
     * server and begin to accept calls.
     */
    public void start() {
        bmixClient.start();
        inputClient.start();
        try {
            for (;;) {
                try {
                    inputClient.waitForGameStart();
                    doGame();
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        } finally {
            bmixClient.stop();
            inputClient.stop();
        }
    }
    
    private void doGame() {
        try {
            setGameRunning(true);
            game.gameStarting(this);
            long startTime = System.currentTimeMillis();
            BufferedImage bi = new BufferedImage(playfieldWidth, playfieldHeight, BufferedImage.TYPE_INT_ARGB);
            for (;;) {
                long when = System.currentTimeMillis() - startTime;
                FrameInfo frameInfo = new FrameInfo(inputClient.getKeystroke(), when);
                Graphics2D g = (Graphics2D) bi.getGraphics();
                try {
                    g.setColor(Color.BLACK); // TODO configurable background colour
                    g.fillRect(0, 0, playfieldWidth, playfieldHeight);
                    boolean keepGoing = game.nextFrame(g, frameInfo);
                    bmixClient.putFrame(bi);
                    if (!keepGoing) break;
                    Thread.sleep((long) ((1.0 / framesPerSecond) * 1000));
                } catch (InterruptedException e) {
                    // not a biggie
                } finally {
                    g.dispose();
                }
            }
        } finally {
            game.gameEnding();
            // TODO last frame delay (config file)
            setGameRunning(false);
        }
    }

    public boolean isGameRunning() {
        return gameRunning;
    }

    public void setGameRunning(boolean gameRunning) {
        this.gameRunning = gameRunning;
    }

    public int getPlayfieldWidth() {
        return playfieldWidth;
    }

    public int getPlayfieldHeight() {
        return playfieldHeight;
    }

    public double getFramesPerSecond() {
        return framesPerSecond;
    }

    public void setFramesPerSecond(double framesPerSecond) {
        this.framesPerSecond = framesPerSecond;
    }
}