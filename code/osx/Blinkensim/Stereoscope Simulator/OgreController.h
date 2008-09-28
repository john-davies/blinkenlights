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

@end