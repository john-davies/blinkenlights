package de.blinkenlights.bvoip.main;

import java.io.IOException;

import org.apache.commons.daemon.DaemonContext;

public class Daemon implements org.apache.commons.daemon.Daemon {
	private String[] arguments;

	public void destroy() {
		// no special cleanup required
	}

	public void init(DaemonContext arg0) throws Exception {
		arguments = arg0.getArguments();
		
	}

	public void start() throws Exception {
		Thread main = new Thread(new Runnable() {
			public void run() {
				try {
					BVoip.main(arguments);
				} catch (IOException e) {
					throw new RuntimeException("error starting",e);
				}	
			}
		});
		main.start();
	}

	public void stop() throws Exception {
		// no special cleanup....		
		// TODO: possibly blank the screen?
	}

}