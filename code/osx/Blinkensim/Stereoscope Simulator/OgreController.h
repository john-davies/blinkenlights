/* OgreController */

#import <Cocoa/Cocoa.h>
#import <Ogre/OgreOSXCocoaView.h>
#import <Ogre/Ogre.h>

@interface OgreController : NSObject
{
	IBOutlet OgreView *ogreView;
	NSColor *diffuseLight;
	NSColor *specularLight;
}
- (IBAction) showWebsite:(id)inSender;
- (IBAction) setCameraPosition:(id)inSender;
- (void)animateCamera;
- (void)setOgreView:(OgreView *)inView;

@end
