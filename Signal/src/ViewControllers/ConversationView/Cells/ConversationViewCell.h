//
//  Copyright (c) 2017 Open Whisper Systems. All rights reserved.
//

@class ConversationViewItem;

@class TSInteraction;
@class ConversationViewCell;
@class OWSContactOffersInteraction;

// TODO: Rework these delegate methods.
@protocol ConversationViewCellDelegate <NSObject>

#pragma mark - System Cell

- (void)didTapSystemMessageWithInteraction:(TSInteraction *)interaction;
- (void)didLongPressSystemMessageCell:(ConversationViewCell *)systemMessageCell
                             fromView:(UIView *)fromView;

#pragma mark - Offers

- (void)tappedUnknownContactBlockOfferMessage:(OWSContactOffersInteraction *)interaction;
- (void)tappedAddToContactsOfferMessage:(OWSContactOffersInteraction *)interaction;
- (void)tappedAddToProfileWhitelistOfferMessage:(OWSContactOffersInteraction *)interaction;

@end

#pragma mark -

// TODO: We should use a custom subclass for each interaction type.
@interface ConversationViewCell : UICollectionViewCell

@property (nonatomic, weak) id<ConversationViewCellDelegate> delegate;

@property (nonatomic) ConversationViewItem * viewItem;

@property (nonatomic) BOOL isCellVisible;

// If this is non-null, we should show the message date header.
@property (nonatomic, nullable) NSAttributedString * messageDateHeaderText;

- (void)configure;

@end