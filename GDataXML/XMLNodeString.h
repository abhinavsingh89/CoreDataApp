//
//  XMLNodeString.h
//

@class NSDictionary;

#import "GDataXMLNode.h"

@interface XMLNodeString : NSObject
{
	NSMutableString*	_str;
	NSString*			_opentag;
	NSString*			_openchildtag;
}

- (NSMutableString*) xmlString;
- (NSData*) dataWithUTF8Encoding;

- (id) initWithString: (NSString*) string;
- (id) initWithTag: (NSString*) tag;
- (id) initWithTag: (NSString*) tag strVal:(NSString*)strVal newLine:(BOOL)newLine;

- (void) startChildTag: (NSString*) tag propString:(NSString*)propString;

- (void) addChildNode: (NSString*) tag strVal:(NSString*)strVal;
- (void) addChildNode: (NSString*) tag intVal:(NSInteger)intVal;
- (void) addChildNode: (NSString*) tag strValArray:(NSArray*)array;

- (void) addChildNode: (XMLNodeString*) anXMLNode;
- (void) addChildNodeDictionary: (NSDictionary*) dictionary;
- (void) addChildNodeString: (NSString*) nodeStr;

- (void) endCurrentTag;

+ (id) xmlNodeStringWithString: (NSString*) string;
+ (id) xmlNodeStringWithTag: (NSString*) tag;
+ (id) xmlNodeStringWithTag: (NSString*) tag strVal:(NSString*)strVal;
+ (id) xmlNodeStringWithTag: (NSString*) tag intVal:(NSInteger)intVal;
+ (id) xmlNodeStringWithTag: (NSString*) tag xmlVal:(XMLNodeString*)xmlVal;

+ (NSString*) stringWithTag: (NSString*) tag strVal:(NSString*)strVal newLine:(BOOL)newLine;
+ (NSString*) stringWithTabAtNewLinesInString: (NSString*)string;

@end



@interface NSXMLNode (EasyAccessors)

- (NSDictionary*) dictionaryForNode;
- (NSString*) stringValueWithTrimming;
- (NSArray*) arrayWithValuesForName:(NSString *)name;

@end

@interface NSXMLElement (EasyAccessors)

- (NSXMLElement*) elementForName:(NSString *)name;
- (NSXMLElement*) elementLikeName:(NSString *)name;

- (NSString*) stringValueForNode: (NSString*)childNodeName;
- (BOOL) boolValueForNode: (NSString*)childNodeName;
- (NSInteger) integerValueForNode: (NSString*)childNodeName;

- (NSString*) stringValueForAttribute: (NSString*)attributeName;
- (BOOL) boolValueForAttribute: (NSString*)attributeName;
- (NSInteger) integerValueForAttribute: (NSString*)attributeName;

- (void) dumpNodes;

@end


