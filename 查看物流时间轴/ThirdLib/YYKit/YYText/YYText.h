//
//  YYText.h
//  YYText <https://github.com/ibireme/YYText>
//
//  Created by ibireme on 15/2/25.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

#if __has_include(<YYText/YYText.h>)
FOUNDATION_EXPORT double YYTextVersionNumber;
FOUNDATION_EXPORT const unsigned char YYTextVersionString[];
#import <YYText/YYLabel.h>
#import <YYText/YYTextView.h>
#import <YYText/YYTextAttribute.h>
#import <YYText/YYTextArchiver.h>
#import <YYText/YYTextParser.h>
#import <YYText/YYTextRunDelegate.h>
#import <YYText/YYTextRubyAnnotation.h>
#import <YYText/YYTextLayout.h>
#import <YYText/YYTextLine.h>
#import <YYText/YYTextInput.h>
#import <YYText/YYTextDebugOption.h>
#import <YYText/YYTextKeyboardManager.h>
#import <YYText/YYTextUtilities.h>
#import <YYText/NSAttributedString+YYText.h>
#import <YYText/NSParagraphStyle+YYText.h>
#import <YYText/UIPasteboard+YYText.h>
#else
#import "YYLabel.h"
#import "YYTextView.h"
#import "YYTextAttribute.h"
#import "YYTextArchiver.h"
#import "YYTextParser.h"
#import "YYTextRunDelegate.h"
#import "YYTextRubyAnnotation.h"
#import "YYTextLayout.h"
#import "YYTextLine.h"
#import "YYTextInput.h"
#import "YYTextDebugOption.h"
#import "YYTextKeyboardManager.h"
#import "YYTextUtilities.h"
#import "NSAttributedString+YYText.h"
#import "NSParagraphStyle+YYText.h"
#import "UIPasteboard+YYText.h"
#import "YYAnimatedImageView.h"


#import "YYKitMacro.h"
#import "NSObject+YYAdd.h"
#import "NSObject+YYAddForKVO.h"
#import "NSObject+YYAddForARC.h"
#import "NSString+YYAdd.h"
#import "NSNumber+YYAdd.h"
#import "NSData+YYAdd.h"
#import "NSArray+YYAdd.h"
#import "NSDictionary+YYAdd.h"
#import "NSDate+YYAdd.h"
#import "NSNotificationCenter+YYAdd.h"
#import "NSKeyedUnarchiver+YYAdd.h"
#import "NSTimer+YYAdd.h"
#import "NSBundle+YYAdd.h"
#import "NSThread+YYAdd.h"

#import "UIColor+YYAdd.h"
#import "UIImage+YYAdd.h"
#import "UIControl+YYAdd.h"
#import "UIBarButtonItem+YYAdd.h"
#import "UIGestureRecognizer+YYAdd.h"
#import "UIView+YYAdd.h"
#import "UIScrollView+YYAdd.h"
#import "UITableView+YYAdd.h"
#import "UITextField+YYAdd.h"
#import "UIScreen+YYAdd.h"
#import "UIDevice+YYAdd.h"
#import "UIApplication+YYAdd.h"
#import "UIFont+YYAdd.h"
#import "UIBezierPath+YYAdd.h"

#import "CALayer+YYAdd.h"
#import "YYCGUtilities.h"
#import "UIImageView+YYWebImage.h"

#import "YYImageCoder.h"



#endif
