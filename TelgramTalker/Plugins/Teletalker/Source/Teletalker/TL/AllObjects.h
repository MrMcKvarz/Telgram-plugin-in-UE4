#pragma once
#include "Engine.h"
#include "Types/COMMON/Public/ResPQ.h"
#include "Types/COMMON/Public/PQInnerData.h"
#include "Types/COMMON/Public/ServerDHParamsFail.h"
#include "Types/COMMON/Public/ServerDHParamsOk.h"
#include "Types/COMMON/Public/ServerDHInnerData.h"
#include "Types/COMMON/Public/ClientDHInnerData.h"
#include "Types/COMMON/Public/DhGenOk.h"
#include "Types/COMMON/Public/DhGenRetry.h"
#include "Types/COMMON/Public/DhGenFail.h"
#include "Types/COMMON/Public/DestroyAuthKeyOk.h"
#include "Types/COMMON/Public/DestroyAuthKeyNone.h"
#include "Types/COMMON/Public/DestroyAuthKeyFail.h"
#include "Functions/COMMON/Public/ReqPq.h"
#include "Functions/COMMON/Public/ReqDHParams.h"
#include "Functions/COMMON/Public/SetClientDHParams.h"
#include "Functions/COMMON/Public/DestroyAuthKey.h"
#include "Types/COMMON/Public/MsgsAck.h"
#include "Types/COMMON/Public/BadMsgNotification.h"
#include "Types/COMMON/Public/BadServerSalt.h"
#include "Types/COMMON/Public/MsgsStateReq.h"
#include "Types/COMMON/Public/MsgsStateInfo.h"
#include "Types/COMMON/Public/MsgsAllInfo.h"
#include "Types/COMMON/Public/MsgDetailedInfo.h"
#include "Types/COMMON/Public/MsgNewDetailedInfo.h"
#include "Types/COMMON/Public/MsgResendReq.h"
#include "Types/COMMON/Public/RpcError.h"
#include "Types/COMMON/Public/RpcAnswerUnknown.h"
#include "Types/COMMON/Public/RpcAnswerDroppedRunning.h"
#include "Types/COMMON/Public/RpcAnswerDropped.h"
#include "Types/COMMON/Public/FutureSalt.h"
#include "Types/COMMON/Public/FutureSalts.h"
#include "Types/COMMON/Public/Pong.h"
#include "Types/COMMON/Public/DestroySessionOk.h"
#include "Types/COMMON/Public/DestroySessionNone.h"
#include "Types/COMMON/Public/NewSessionCreated.h"
#include "Types/COMMON/Public/HttpWait.h"
#include "Types/COMMON/Public/IpPort.h"
#include "Types/HELP/Public/ConfigSimple.h"
#include "Functions/COMMON/Public/RpcDropAnswer.h"
#include "Functions/COMMON/Public/GetFutureSalts.h"
#include "Functions/COMMON/Public/Ping.h"
#include "Functions/COMMON/Public/PingDelayDisconnect.h"
#include "Functions/COMMON/Public/DestroySession.h"
#include "Functions/CONTEST/Public/SaveDeveloperInfo.h"
#include "Types/COMMON/Public/BoolFalse.h"
#include "Types/COMMON/Public/BoolTrue.h"
#include "Types/COMMON/Public/True.h"
#include "Types/COMMON/Public/Error.h"
#include "Types/COMMON/Public/Null.h"
#include "Types/COMMON/Public/InputPeerEmpty.h"
#include "Types/COMMON/Public/InputPeerSelf.h"
#include "Types/COMMON/Public/InputPeerChat.h"
#include "Types/COMMON/Public/InputPeerUser.h"
#include "Types/COMMON/Public/InputPeerChannel.h"
#include "Types/COMMON/Public/InputUserEmpty.h"
#include "Types/COMMON/Public/InputUserSelf.h"
#include "Types/COMMON/Public/InputUser.h"
#include "Types/COMMON/Public/InputPhoneContact.h"
#include "Types/COMMON/Public/InputFile.h"
#include "Types/COMMON/Public/InputFileBig.h"
#include "Types/COMMON/Public/InputMediaEmpty.h"
#include "Types/COMMON/Public/InputMediaUploadedPhoto.h"
#include "Types/COMMON/Public/InputMediaPhoto.h"
#include "Types/COMMON/Public/InputMediaGeoPoint.h"
#include "Types/COMMON/Public/InputMediaContact.h"
#include "Types/COMMON/Public/InputMediaUploadedDocument.h"
#include "Types/COMMON/Public/InputMediaDocument.h"
#include "Types/COMMON/Public/InputMediaVenue.h"
#include "Types/COMMON/Public/InputMediaGifExternal.h"
#include "Types/COMMON/Public/InputMediaPhotoExternal.h"
#include "Types/COMMON/Public/InputMediaDocumentExternal.h"
#include "Types/COMMON/Public/InputMediaGame.h"
#include "Types/COMMON/Public/InputMediaInvoice.h"
#include "Types/COMMON/Public/InputMediaGeoLive.h"
#include "Types/COMMON/Public/InputChatPhotoEmpty.h"
#include "Types/COMMON/Public/InputChatUploadedPhoto.h"
#include "Types/COMMON/Public/InputChatPhoto.h"
#include "Types/COMMON/Public/InputGeoPointEmpty.h"
#include "Types/COMMON/Public/InputGeoPoint.h"
#include "Types/COMMON/Public/InputPhotoEmpty.h"
#include "Types/COMMON/Public/InputPhoto.h"
#include "Types/COMMON/Public/InputFileLocation.h"
#include "Types/COMMON/Public/InputEncryptedFileLocation.h"
#include "Types/COMMON/Public/InputDocumentFileLocation.h"
#include "Types/COMMON/Public/InputAppEvent.h"
#include "Types/COMMON/Public/PeerUser.h"
#include "Types/COMMON/Public/PeerChat.h"
#include "Types/COMMON/Public/PeerChannel.h"
#include "Types/STORAGE/Public/FileUnknown.h"
#include "Types/STORAGE/Public/FilePartial.h"
#include "Types/STORAGE/Public/FileJpeg.h"
#include "Types/STORAGE/Public/FileGif.h"
#include "Types/STORAGE/Public/FilePng.h"
#include "Types/STORAGE/Public/FilePdf.h"
#include "Types/STORAGE/Public/FileMp3.h"
#include "Types/STORAGE/Public/FileMov.h"
#include "Types/STORAGE/Public/FileMp4.h"
#include "Types/STORAGE/Public/FileWebp.h"
#include "Types/COMMON/Public/FileLocationUnavailable.h"
#include "Types/COMMON/Public/FileLocation.h"
#include "Types/COMMON/Public/UserEmpty.h"
#include "Types/COMMON/Public/User.h"
#include "Types/COMMON/Public/UserProfilePhotoEmpty.h"
#include "Types/COMMON/Public/UserProfilePhoto.h"
#include "Types/COMMON/Public/UserStatusEmpty.h"
#include "Types/COMMON/Public/UserStatusOnline.h"
#include "Types/COMMON/Public/UserStatusOffline.h"
#include "Types/COMMON/Public/UserStatusRecently.h"
#include "Types/COMMON/Public/UserStatusLastWeek.h"
#include "Types/COMMON/Public/UserStatusLastMonth.h"
#include "Types/COMMON/Public/ChatEmpty.h"
#include "Types/COMMON/Public/Chat.h"
#include "Types/COMMON/Public/ChatForbidden.h"
#include "Types/COMMON/Public/Channel.h"
#include "Types/COMMON/Public/ChannelForbidden.h"
#include "Types/COMMON/Public/ChatFull.h"
#include "Types/COMMON/Public/ChannelFull.h"
#include "Types/COMMON/Public/ChatParticipant.h"
#include "Types/COMMON/Public/ChatParticipantCreator.h"
#include "Types/COMMON/Public/ChatParticipantAdmin.h"
#include "Types/COMMON/Public/ChatParticipantsForbidden.h"
#include "Types/COMMON/Public/ChatParticipants.h"
#include "Types/COMMON/Public/ChatPhotoEmpty.h"
#include "Types/COMMON/Public/ChatPhoto.h"
#include "Types/COMMON/Public/MessageEmpty.h"
#include "Types/COMMON/Public/Message.h"
#include "Types/COMMON/Public/MessageService.h"
#include "Types/COMMON/Public/MessageMediaEmpty.h"
#include "Types/COMMON/Public/MessageMediaPhoto.h"
#include "Types/COMMON/Public/MessageMediaGeo.h"
#include "Types/COMMON/Public/MessageMediaContact.h"
#include "Types/COMMON/Public/MessageMediaUnsupported.h"
#include "Types/COMMON/Public/MessageMediaDocument.h"
#include "Types/COMMON/Public/MessageMediaWebPage.h"
#include "Types/COMMON/Public/MessageMediaVenue.h"
#include "Types/COMMON/Public/MessageMediaGame.h"
#include "Types/COMMON/Public/MessageMediaInvoice.h"
#include "Types/COMMON/Public/MessageMediaGeoLive.h"
#include "Types/COMMON/Public/MessageActionEmpty.h"
#include "Types/COMMON/Public/MessageActionChatCreate.h"
#include "Types/COMMON/Public/MessageActionChatEditTitle.h"
#include "Types/COMMON/Public/MessageActionChatEditPhoto.h"
#include "Types/COMMON/Public/MessageActionChatDeletePhoto.h"
#include "Types/COMMON/Public/MessageActionChatAddUser.h"
#include "Types/COMMON/Public/MessageActionChatDeleteUser.h"
#include "Types/COMMON/Public/MessageActionChatJoinedByLink.h"
#include "Types/COMMON/Public/MessageActionChannelCreate.h"
#include "Types/COMMON/Public/MessageActionChatMigrateTo.h"
#include "Types/COMMON/Public/MessageActionChannelMigrateFrom.h"
#include "Types/COMMON/Public/MessageActionPinMessage.h"
#include "Types/COMMON/Public/MessageActionHistoryClear.h"
#include "Types/COMMON/Public/MessageActionGameScore.h"
#include "Types/COMMON/Public/MessageActionPaymentSentMe.h"
#include "Types/COMMON/Public/MessageActionPaymentSent.h"
#include "Types/COMMON/Public/MessageActionPhoneCall.h"
#include "Types/COMMON/Public/MessageActionScreenshotTaken.h"
#include "Types/COMMON/Public/MessageActionCustomAction.h"
#include "Types/COMMON/Public/Dialog.h"
#include "Types/COMMON/Public/PhotoEmpty.h"
#include "Types/COMMON/Public/Photo.h"
#include "Types/COMMON/Public/PhotoSizeEmpty.h"
#include "Types/COMMON/Public/PhotoSize.h"
#include "Types/COMMON/Public/PhotoCachedSize.h"
#include "Types/COMMON/Public/GeoPointEmpty.h"
#include "Types/COMMON/Public/GeoPoint.h"
#include "Types/AUTH/Public/CheckedPhone.h"
#include "Types/AUTH/Public/SentCode.h"
#include "Types/AUTH/Public/Authorization.h"
#include "Types/AUTH/Public/ExportedAuthorization.h"
#include "Types/COMMON/Public/InputNotifyPeer.h"
#include "Types/COMMON/Public/InputNotifyUsers.h"
#include "Types/COMMON/Public/InputNotifyChats.h"
#include "Types/COMMON/Public/InputNotifyAll.h"
#include "Types/COMMON/Public/InputPeerNotifyEventsEmpty.h"
#include "Types/COMMON/Public/InputPeerNotifyEventsAll.h"
#include "Types/COMMON/Public/InputPeerNotifySettings.h"
#include "Types/COMMON/Public/PeerNotifyEventsEmpty.h"
#include "Types/COMMON/Public/PeerNotifyEventsAll.h"
#include "Types/COMMON/Public/PeerNotifySettingsEmpty.h"
#include "Types/COMMON/Public/PeerNotifySettings.h"
#include "Types/COMMON/Public/PeerSettings.h"
#include "Types/COMMON/Public/WallPaper.h"
#include "Types/COMMON/Public/WallPaperSolid.h"
#include "Types/COMMON/Public/InputReportReasonSpam.h"
#include "Types/COMMON/Public/InputReportReasonViolence.h"
#include "Types/COMMON/Public/InputReportReasonPornography.h"
#include "Types/COMMON/Public/InputReportReasonOther.h"
#include "Types/COMMON/Public/UserFull.h"
#include "Types/COMMON/Public/Contact.h"
#include "Types/COMMON/Public/ImportedContact.h"
#include "Types/COMMON/Public/ContactBlocked.h"
#include "Types/COMMON/Public/ContactStatus.h"
#include "Types/CONTACTS/Public/Link.h"
#include "Types/CONTACTS/Public/ContactsNotModified.h"
#include "Types/CONTACTS/Public/Contacts.h"
#include "Types/CONTACTS/Public/ImportedContacts.h"
#include "Types/CONTACTS/Public/Blocked.h"
#include "Types/CONTACTS/Public/BlockedSlice.h"
#include "Types/MESSAGES/Public/Dialogs.h"
#include "Types/MESSAGES/Public/DialogsSlice.h"
#include "Types/MESSAGES/Public/Messages.h"
#include "Types/MESSAGES/Public/MessagesSlice.h"
#include "Types/MESSAGES/Public/ChannelMessages.h"
#include "Types/MESSAGES/Public/Chats.h"
#include "Types/MESSAGES/Public/ChatsSlice.h"
#include "Types/MESSAGES/Public/ChatFull.h"
#include "Types/MESSAGES/Public/AffectedHistory.h"
#include "Types/COMMON/Public/InputMessagesFilterEmpty.h"
#include "Types/COMMON/Public/InputMessagesFilterPhotos.h"
#include "Types/COMMON/Public/InputMessagesFilterVideo.h"
#include "Types/COMMON/Public/InputMessagesFilterPhotoVideo.h"
#include "Types/COMMON/Public/InputMessagesFilterPhotoVideoDocuments.h"
#include "Types/COMMON/Public/InputMessagesFilterDocument.h"
#include "Types/COMMON/Public/InputMessagesFilterUrl.h"
#include "Types/COMMON/Public/InputMessagesFilterGif.h"
#include "Types/COMMON/Public/InputMessagesFilterVoice.h"
#include "Types/COMMON/Public/InputMessagesFilterMusic.h"
#include "Types/COMMON/Public/InputMessagesFilterChatPhotos.h"
#include "Types/COMMON/Public/InputMessagesFilterPhoneCalls.h"
#include "Types/COMMON/Public/InputMessagesFilterRoundVoice.h"
#include "Types/COMMON/Public/InputMessagesFilterRoundVideo.h"
#include "Types/COMMON/Public/InputMessagesFilterMyMentions.h"
#include "Types/COMMON/Public/InputMessagesFilterContacts.h"
#include "Types/COMMON/Public/InputMessagesFilterGeo.h"
#include "Types/COMMON/Public/UpdateNewMessage.h"
#include "Types/COMMON/Public/UpdateMessageID.h"
#include "Types/COMMON/Public/UpdateDeleteMessages.h"
#include "Types/COMMON/Public/UpdateUserTyping.h"
#include "Types/COMMON/Public/UpdateChatUserTyping.h"
#include "Types/COMMON/Public/UpdateChatParticipants.h"
#include "Types/COMMON/Public/UpdateUserStatus.h"
#include "Types/COMMON/Public/UpdateUserName.h"
#include "Types/COMMON/Public/UpdateUserPhoto.h"
#include "Types/COMMON/Public/UpdateContactRegistered.h"
#include "Types/COMMON/Public/UpdateContactLink.h"
#include "Types/COMMON/Public/UpdateNewEncryptedMessage.h"
#include "Types/COMMON/Public/UpdateEncryptedChatTyping.h"
#include "Types/COMMON/Public/UpdateEncryption.h"
#include "Types/COMMON/Public/UpdateEncryptedMessagesRead.h"
#include "Types/COMMON/Public/UpdateChatParticipantAdd.h"
#include "Types/COMMON/Public/UpdateChatParticipantDelete.h"
#include "Types/COMMON/Public/UpdateDcOptions.h"
#include "Types/COMMON/Public/UpdateUserBlocked.h"
#include "Types/COMMON/Public/UpdateNotifySettings.h"
#include "Types/COMMON/Public/UpdateServiceNotification.h"
#include "Types/COMMON/Public/UpdatePrivacy.h"
#include "Types/COMMON/Public/UpdateUserPhone.h"
#include "Types/COMMON/Public/UpdateReadHistoryInbox.h"
#include "Types/COMMON/Public/UpdateReadHistoryOutbox.h"
#include "Types/COMMON/Public/UpdateWebPage.h"
#include "Types/COMMON/Public/UpdateReadMessagesContents.h"
#include "Types/COMMON/Public/UpdateChannelTooLong.h"
#include "Types/COMMON/Public/UpdateChannel.h"
#include "Types/COMMON/Public/UpdateNewChannelMessage.h"
#include "Types/COMMON/Public/UpdateReadChannelInbox.h"
#include "Types/COMMON/Public/UpdateDeleteChannelMessages.h"
#include "Types/COMMON/Public/UpdateChannelMessageViews.h"
#include "Types/COMMON/Public/UpdateChatAdmins.h"
#include "Types/COMMON/Public/UpdateChatParticipantAdmin.h"
#include "Types/COMMON/Public/UpdateNewStickerSet.h"
#include "Types/COMMON/Public/UpdateStickerSetsOrder.h"
#include "Types/COMMON/Public/UpdateStickerSets.h"
#include "Types/COMMON/Public/UpdateSavedGifs.h"
#include "Types/COMMON/Public/UpdateBotInlineQuery.h"
#include "Types/COMMON/Public/UpdateBotInlineSend.h"
#include "Types/COMMON/Public/UpdateEditChannelMessage.h"
#include "Types/COMMON/Public/UpdateChannelPinnedMessage.h"
#include "Types/COMMON/Public/UpdateBotCallbackQuery.h"
#include "Types/COMMON/Public/UpdateEditMessage.h"
#include "Types/COMMON/Public/UpdateInlineBotCallbackQuery.h"
#include "Types/COMMON/Public/UpdateReadChannelOutbox.h"
#include "Types/COMMON/Public/UpdateDraftMessage.h"
#include "Types/COMMON/Public/UpdateReadFeaturedStickers.h"
#include "Types/COMMON/Public/UpdateRecentStickers.h"
#include "Types/COMMON/Public/UpdateConfig.h"
#include "Types/COMMON/Public/UpdatePtsChanged.h"
#include "Types/COMMON/Public/UpdateChannelWebPage.h"
#include "Types/COMMON/Public/UpdateDialogPinned.h"
#include "Types/COMMON/Public/UpdatePinnedDialogs.h"
#include "Types/COMMON/Public/UpdateBotWebhookJSON.h"
#include "Types/COMMON/Public/UpdateBotWebhookJSONQuery.h"
#include "Types/COMMON/Public/UpdateBotShippingQuery.h"
#include "Types/COMMON/Public/UpdateBotPrecheckoutQuery.h"
#include "Types/COMMON/Public/UpdatePhoneCall.h"
#include "Types/COMMON/Public/UpdateLangPackTooLong.h"
#include "Types/COMMON/Public/UpdateLangPack.h"
#include "Types/COMMON/Public/UpdateFavedStickers.h"
#include "Types/COMMON/Public/UpdateChannelReadMessagesContents.h"
#include "Types/COMMON/Public/UpdateContactsReset.h"
#include "Types/COMMON/Public/UpdateChannelAvailableMessages.h"
#include "Types/UPDATES/Public/State.h"
#include "Types/UPDATES/Public/DifferenceEmpty.h"
#include "Types/UPDATES/Public/Difference.h"
#include "Types/UPDATES/Public/DifferenceSlice.h"
#include "Types/UPDATES/Public/DifferenceTooLong.h"
#include "Types/COMMON/Public/UpdatesTooLong.h"
#include "Types/COMMON/Public/UpdateShortMessage.h"
#include "Types/COMMON/Public/UpdateShortChatMessage.h"
#include "Types/COMMON/Public/UpdateShort.h"
#include "Types/COMMON/Public/UpdatesCombined.h"
#include "Types/COMMON/Public/Updates.h"
#include "Types/COMMON/Public/UpdateShortSentMessage.h"
#include "Types/PHOTOS/Public/Photos.h"
#include "Types/PHOTOS/Public/PhotosSlice.h"
#include "Types/PHOTOS/Public/Photo.h"
#include "Types/UPLOAD/Public/File.h"
#include "Types/UPLOAD/Public/FileCdnRedirect.h"
#include "Types/COMMON/Public/DcOption.h"
#include "Types/COMMON/Public/Config.h"
#include "Types/COMMON/Public/NearestDc.h"
#include "Types/HELP/Public/AppUpdate.h"
#include "Types/HELP/Public/NoAppUpdate.h"
#include "Types/HELP/Public/InviteText.h"
#include "Types/COMMON/Public/EncryptedChatEmpty.h"
#include "Types/COMMON/Public/EncryptedChatWaiting.h"
#include "Types/COMMON/Public/EncryptedChatRequested.h"
#include "Types/COMMON/Public/EncryptedChat.h"
#include "Types/COMMON/Public/EncryptedChatDiscarded.h"
#include "Types/COMMON/Public/InputEncryptedChat.h"
#include "Types/COMMON/Public/EncryptedFileEmpty.h"
#include "Types/COMMON/Public/EncryptedFile.h"
#include "Types/COMMON/Public/InputEncryptedFileEmpty.h"
#include "Types/COMMON/Public/InputEncryptedFileUploaded.h"
#include "Types/COMMON/Public/InputEncryptedFile.h"
#include "Types/COMMON/Public/InputEncryptedFileBigUploaded.h"
#include "Types/COMMON/Public/EncryptedMessage.h"
#include "Types/COMMON/Public/EncryptedMessageService.h"
#include "Types/MESSAGES/Public/DhConfigNotModified.h"
#include "Types/MESSAGES/Public/DhConfig.h"
#include "Types/MESSAGES/Public/SentEncryptedMessage.h"
#include "Types/MESSAGES/Public/SentEncryptedFile.h"
#include "Types/COMMON/Public/InputDocumentEmpty.h"
#include "Types/COMMON/Public/InputDocument.h"
#include "Types/COMMON/Public/DocumentEmpty.h"
#include "Types/COMMON/Public/Document.h"
#include "Types/HELP/Public/Support.h"
#include "Types/COMMON/Public/NotifyPeer.h"
#include "Types/COMMON/Public/NotifyUsers.h"
#include "Types/COMMON/Public/NotifyChats.h"
#include "Types/COMMON/Public/NotifyAll.h"
#include "Types/COMMON/Public/SendMessageTypingAction.h"
#include "Types/COMMON/Public/SendMessageCancelAction.h"
#include "Types/COMMON/Public/SendMessageRecordVideoAction.h"
#include "Types/COMMON/Public/SendMessageUploadVideoAction.h"
#include "Types/COMMON/Public/SendMessageRecordAudioAction.h"
#include "Types/COMMON/Public/SendMessageUploadAudioAction.h"
#include "Types/COMMON/Public/SendMessageUploadPhotoAction.h"
#include "Types/COMMON/Public/SendMessageUploadDocumentAction.h"
#include "Types/COMMON/Public/SendMessageGeoLocationAction.h"
#include "Types/COMMON/Public/SendMessageChooseContactAction.h"
#include "Types/COMMON/Public/SendMessageGamePlayAction.h"
#include "Types/COMMON/Public/SendMessageRecordRoundAction.h"
#include "Types/COMMON/Public/SendMessageUploadRoundAction.h"
#include "Types/CONTACTS/Public/Found.h"
#include "Types/COMMON/Public/InputPrivacyKeyStatusTimestamp.h"
#include "Types/COMMON/Public/InputPrivacyKeyChatInvite.h"
#include "Types/COMMON/Public/InputPrivacyKeyPhoneCall.h"
#include "Types/COMMON/Public/PrivacyKeyStatusTimestamp.h"
#include "Types/COMMON/Public/PrivacyKeyChatInvite.h"
#include "Types/COMMON/Public/PrivacyKeyPhoneCall.h"
#include "Types/COMMON/Public/InputPrivacyValueAllowContacts.h"
#include "Types/COMMON/Public/InputPrivacyValueAllowAll.h"
#include "Types/COMMON/Public/InputPrivacyValueAllowUsers.h"
#include "Types/COMMON/Public/InputPrivacyValueDisallowContacts.h"
#include "Types/COMMON/Public/InputPrivacyValueDisallowAll.h"
#include "Types/COMMON/Public/InputPrivacyValueDisallowUsers.h"
#include "Types/COMMON/Public/PrivacyValueAllowContacts.h"
#include "Types/COMMON/Public/PrivacyValueAllowAll.h"
#include "Types/COMMON/Public/PrivacyValueAllowUsers.h"
#include "Types/COMMON/Public/PrivacyValueDisallowContacts.h"
#include "Types/COMMON/Public/PrivacyValueDisallowAll.h"
#include "Types/COMMON/Public/PrivacyValueDisallowUsers.h"
#include "Types/ACCOUNT/Public/PrivacyRules.h"
#include "Types/COMMON/Public/AccountDaysTTL.h"
#include "Types/COMMON/Public/DocumentAttributeImageSize.h"
#include "Types/COMMON/Public/DocumentAttributeAnimated.h"
#include "Types/COMMON/Public/DocumentAttributeSticker.h"
#include "Types/COMMON/Public/DocumentAttributeVideo.h"
#include "Types/COMMON/Public/DocumentAttributeAudio.h"
#include "Types/COMMON/Public/DocumentAttributeFilename.h"
#include "Types/COMMON/Public/DocumentAttributeHasStickers.h"
#include "Types/MESSAGES/Public/StickersNotModified.h"
#include "Types/MESSAGES/Public/Stickers.h"
#include "Types/COMMON/Public/StickerPack.h"
#include "Types/MESSAGES/Public/AllStickersNotModified.h"
#include "Types/MESSAGES/Public/AllStickers.h"
#include "Types/COMMON/Public/DisabledFeature.h"
#include "Types/MESSAGES/Public/AffectedMessages.h"
#include "Types/COMMON/Public/ContactLinkUnknown.h"
#include "Types/COMMON/Public/ContactLinkNone.h"
#include "Types/COMMON/Public/ContactLinkHasPhone.h"
#include "Types/COMMON/Public/ContactLinkContact.h"
#include "Types/COMMON/Public/WebPageEmpty.h"
#include "Types/COMMON/Public/WebPagePending.h"
#include "Types/COMMON/Public/WebPage.h"
#include "Types/COMMON/Public/WebPageNotModified.h"
#include "Types/COMMON/Public/Authorization.h"
#include "Types/ACCOUNT/Public/Authorizations.h"
#include "Types/ACCOUNT/Public/NoPassword.h"
#include "Types/ACCOUNT/Public/Password.h"
#include "Types/ACCOUNT/Public/PasswordSettings.h"
#include "Types/ACCOUNT/Public/PasswordInputSettings.h"
#include "Types/AUTH/Public/PasswordRecovery.h"
#include "Types/COMMON/Public/ReceivedNotifyMessage.h"
#include "Types/COMMON/Public/ChatInviteEmpty.h"
#include "Types/COMMON/Public/ChatInviteExported.h"
#include "Types/COMMON/Public/ChatInviteAlready.h"
#include "Types/COMMON/Public/ChatInvite.h"
#include "Types/COMMON/Public/InputStickerSetEmpty.h"
#include "Types/COMMON/Public/InputStickerSetID.h"
#include "Types/COMMON/Public/InputStickerSetShortName.h"
#include "Types/COMMON/Public/StickerSet.h"
#include "Types/MESSAGES/Public/StickerSet.h"
#include "Types/COMMON/Public/BotCommand.h"
#include "Types/COMMON/Public/BotInfo.h"
#include "Types/COMMON/Public/KeyboardButton.h"
#include "Types/COMMON/Public/KeyboardButtonUrl.h"
#include "Types/COMMON/Public/KeyboardButtonCallback.h"
#include "Types/COMMON/Public/KeyboardButtonRequestPhone.h"
#include "Types/COMMON/Public/KeyboardButtonRequestGeoLocation.h"
#include "Types/COMMON/Public/KeyboardButtonSwitchInline.h"
#include "Types/COMMON/Public/KeyboardButtonGame.h"
#include "Types/COMMON/Public/KeyboardButtonBuy.h"
#include "Types/COMMON/Public/KeyboardButtonRow.h"
#include "Types/COMMON/Public/ReplyKeyboardHide.h"
#include "Types/COMMON/Public/ReplyKeyboardForceReply.h"
#include "Types/COMMON/Public/ReplyKeyboardMarkup.h"
#include "Types/COMMON/Public/ReplyInlineMarkup.h"
#include "Types/COMMON/Public/MessageEntityUnknown.h"
#include "Types/COMMON/Public/MessageEntityMention.h"
#include "Types/COMMON/Public/MessageEntityHashtag.h"
#include "Types/COMMON/Public/MessageEntityBotCommand.h"
#include "Types/COMMON/Public/MessageEntityUrl.h"
#include "Types/COMMON/Public/MessageEntityEmail.h"
#include "Types/COMMON/Public/MessageEntityBold.h"
#include "Types/COMMON/Public/MessageEntityItalic.h"
#include "Types/COMMON/Public/MessageEntityCode.h"
#include "Types/COMMON/Public/MessageEntityPre.h"
#include "Types/COMMON/Public/MessageEntityTextUrl.h"
#include "Types/COMMON/Public/MessageEntityMentionName.h"
#include "Types/COMMON/Public/InputMessageEntityMentionName.h"
#include "Types/COMMON/Public/InputChannelEmpty.h"
#include "Types/COMMON/Public/InputChannel.h"
#include "Types/CONTACTS/Public/ResolvedPeer.h"
#include "Types/COMMON/Public/MessageRange.h"
#include "Types/UPDATES/Public/ChannelDifferenceEmpty.h"
#include "Types/UPDATES/Public/ChannelDifferenceTooLong.h"
#include "Types/UPDATES/Public/ChannelDifference.h"
#include "Types/COMMON/Public/ChannelMessagesFilterEmpty.h"
#include "Types/COMMON/Public/ChannelMessagesFilter.h"
#include "Types/COMMON/Public/ChannelParticipant.h"
#include "Types/COMMON/Public/ChannelParticipantSelf.h"
#include "Types/COMMON/Public/ChannelParticipantCreator.h"
#include "Types/COMMON/Public/ChannelParticipantAdmin.h"
#include "Types/COMMON/Public/ChannelParticipantBanned.h"
#include "Types/COMMON/Public/ChannelParticipantsRecent.h"
#include "Types/COMMON/Public/ChannelParticipantsAdmins.h"
#include "Types/COMMON/Public/ChannelParticipantsKicked.h"
#include "Types/COMMON/Public/ChannelParticipantsBots.h"
#include "Types/COMMON/Public/ChannelParticipantsBanned.h"
#include "Types/COMMON/Public/ChannelParticipantsSearch.h"
#include "Types/CHANNELS/Public/ChannelParticipants.h"
#include "Types/CHANNELS/Public/ChannelParticipantsNotModified.h"
#include "Types/CHANNELS/Public/ChannelParticipant.h"
#include "Types/HELP/Public/TermsOfService.h"
#include "Types/COMMON/Public/FoundGif.h"
#include "Types/COMMON/Public/FoundGifCached.h"
#include "Types/MESSAGES/Public/FoundGifs.h"
#include "Types/MESSAGES/Public/SavedGifsNotModified.h"
#include "Types/MESSAGES/Public/SavedGifs.h"
#include "Types/COMMON/Public/InputBotInlineMessageMediaAuto.h"
#include "Types/COMMON/Public/InputBotInlineMessageText.h"
#include "Types/COMMON/Public/InputBotInlineMessageMediaGeo.h"
#include "Types/COMMON/Public/InputBotInlineMessageMediaVenue.h"
#include "Types/COMMON/Public/InputBotInlineMessageMediaContact.h"
#include "Types/COMMON/Public/InputBotInlineMessageGame.h"
#include "Types/COMMON/Public/InputBotInlineResult.h"
#include "Types/COMMON/Public/InputBotInlineResultPhoto.h"
#include "Types/COMMON/Public/InputBotInlineResultDocument.h"
#include "Types/COMMON/Public/InputBotInlineResultGame.h"
#include "Types/COMMON/Public/BotInlineMessageMediaAuto.h"
#include "Types/COMMON/Public/BotInlineMessageText.h"
#include "Types/COMMON/Public/BotInlineMessageMediaGeo.h"
#include "Types/COMMON/Public/BotInlineMessageMediaVenue.h"
#include "Types/COMMON/Public/BotInlineMessageMediaContact.h"
#include "Types/COMMON/Public/BotInlineResult.h"
#include "Types/COMMON/Public/BotInlineMediaResult.h"
#include "Types/MESSAGES/Public/BotResults.h"
#include "Types/COMMON/Public/ExportedMessageLink.h"
#include "Types/COMMON/Public/MessageFwdHeader.h"
#include "Types/AUTH/Public/CodeTypeSms.h"
#include "Types/AUTH/Public/CodeTypeCall.h"
#include "Types/AUTH/Public/CodeTypeFlashCall.h"
#include "Types/AUTH/Public/SentCodeTypeApp.h"
#include "Types/AUTH/Public/SentCodeTypeSms.h"
#include "Types/AUTH/Public/SentCodeTypeCall.h"
#include "Types/AUTH/Public/SentCodeTypeFlashCall.h"
#include "Types/MESSAGES/Public/BotCallbackAnswer.h"
#include "Types/MESSAGES/Public/MessageEditData.h"
#include "Types/COMMON/Public/InputBotInlineMessageID.h"
#include "Types/COMMON/Public/InlineBotSwitchPM.h"
#include "Types/MESSAGES/Public/PeerDialogs.h"
#include "Types/COMMON/Public/TopPeer.h"
#include "Types/COMMON/Public/TopPeerCategoryBotsPM.h"
#include "Types/COMMON/Public/TopPeerCategoryBotsInline.h"
#include "Types/COMMON/Public/TopPeerCategoryCorrespondents.h"
#include "Types/COMMON/Public/TopPeerCategoryGroups.h"
#include "Types/COMMON/Public/TopPeerCategoryChannels.h"
#include "Types/COMMON/Public/TopPeerCategoryPhoneCalls.h"
#include "Types/COMMON/Public/TopPeerCategoryPeers.h"
#include "Types/CONTACTS/Public/TopPeersNotModified.h"
#include "Types/CONTACTS/Public/TopPeers.h"
#include "Types/COMMON/Public/DraftMessageEmpty.h"
#include "Types/COMMON/Public/DraftMessage.h"
#include "Types/MESSAGES/Public/FeaturedStickersNotModified.h"
#include "Types/MESSAGES/Public/FeaturedStickers.h"
#include "Types/MESSAGES/Public/RecentStickersNotModified.h"
#include "Types/MESSAGES/Public/RecentStickers.h"
#include "Types/MESSAGES/Public/ArchivedStickers.h"
#include "Types/MESSAGES/Public/StickerSetInstallResultSuccess.h"
#include "Types/MESSAGES/Public/StickerSetInstallResultArchive.h"
#include "Types/COMMON/Public/StickerSetCovered.h"
#include "Types/COMMON/Public/StickerSetMultiCovered.h"
#include "Types/COMMON/Public/MaskCoords.h"
#include "Types/COMMON/Public/InputStickeredMediaPhoto.h"
#include "Types/COMMON/Public/InputStickeredMediaDocument.h"
#include "Types/COMMON/Public/Game.h"
#include "Types/COMMON/Public/InputGameID.h"
#include "Types/COMMON/Public/InputGameShortName.h"
#include "Types/COMMON/Public/HighScore.h"
#include "Types/MESSAGES/Public/HighScores.h"
#include "Types/COMMON/Public/TextEmpty.h"
#include "Types/COMMON/Public/TextPlain.h"
#include "Types/COMMON/Public/TextBold.h"
#include "Types/COMMON/Public/TextItalic.h"
#include "Types/COMMON/Public/TextUnderline.h"
#include "Types/COMMON/Public/TextStrike.h"
#include "Types/COMMON/Public/TextFixed.h"
#include "Types/COMMON/Public/TextUrl.h"
#include "Types/COMMON/Public/TextEmail.h"
#include "Types/COMMON/Public/TextConcat.h"
#include "Types/COMMON/Public/PageBlockUnsupported.h"
#include "Types/COMMON/Public/PageBlockTitle.h"
#include "Types/COMMON/Public/PageBlockSubtitle.h"
#include "Types/COMMON/Public/PageBlockAuthorDate.h"
#include "Types/COMMON/Public/PageBlockHeader.h"
#include "Types/COMMON/Public/PageBlockSubheader.h"
#include "Types/COMMON/Public/PageBlockParagraph.h"
#include "Types/COMMON/Public/PageBlockPreformatted.h"
#include "Types/COMMON/Public/PageBlockFooter.h"
#include "Types/COMMON/Public/PageBlockDivider.h"
#include "Types/COMMON/Public/PageBlockAnchor.h"
#include "Types/COMMON/Public/PageBlockList.h"
#include "Types/COMMON/Public/PageBlockBlockquote.h"
#include "Types/COMMON/Public/PageBlockPullquote.h"
#include "Types/COMMON/Public/PageBlockPhoto.h"
#include "Types/COMMON/Public/PageBlockVideo.h"
#include "Types/COMMON/Public/PageBlockCover.h"
#include "Types/COMMON/Public/PageBlockEmbed.h"
#include "Types/COMMON/Public/PageBlockEmbedPost.h"
#include "Types/COMMON/Public/PageBlockCollage.h"
#include "Types/COMMON/Public/PageBlockSlideshow.h"
#include "Types/COMMON/Public/PageBlockChannel.h"
#include "Types/COMMON/Public/PageBlockAudio.h"
#include "Types/COMMON/Public/PagePart.h"
#include "Types/COMMON/Public/PageFull.h"
#include "Types/COMMON/Public/PhoneCallDiscardReasonMissed.h"
#include "Types/COMMON/Public/PhoneCallDiscardReasonDisconnect.h"
#include "Types/COMMON/Public/PhoneCallDiscardReasonHangup.h"
#include "Types/COMMON/Public/PhoneCallDiscardReasonBusy.h"
#include "Types/COMMON/Public/DataJSON.h"
#include "Types/COMMON/Public/LabeledPrice.h"
#include "Types/COMMON/Public/Invoice.h"
#include "Types/COMMON/Public/PaymentCharge.h"
#include "Types/COMMON/Public/PostAddress.h"
#include "Types/COMMON/Public/PaymentRequestedInfo.h"
#include "Types/COMMON/Public/PaymentSavedCredentialsCard.h"
#include "Types/COMMON/Public/WebDocument.h"
#include "Types/COMMON/Public/InputWebDocument.h"
#include "Types/COMMON/Public/InputWebFileLocation.h"
#include "Types/UPLOAD/Public/WebFile.h"
#include "Types/PAYMENTS/Public/PaymentForm.h"
#include "Types/PAYMENTS/Public/ValidatedRequestedInfo.h"
#include "Types/PAYMENTS/Public/PaymentResult.h"
#include "Types/PAYMENTS/Public/PaymentVerficationNeeded.h"
#include "Types/PAYMENTS/Public/PaymentReceipt.h"
#include "Types/PAYMENTS/Public/SavedInfo.h"
#include "Types/COMMON/Public/InputPaymentCredentialsSaved.h"
#include "Types/COMMON/Public/InputPaymentCredentials.h"
#include "Types/ACCOUNT/Public/TmpPassword.h"
#include "Types/COMMON/Public/ShippingOption.h"
#include "Types/COMMON/Public/InputStickerSetItem.h"
#include "Types/COMMON/Public/InputPhoneCall.h"
#include "Types/COMMON/Public/PhoneCallEmpty.h"
#include "Types/COMMON/Public/PhoneCallWaiting.h"
#include "Types/COMMON/Public/PhoneCallRequested.h"
#include "Types/COMMON/Public/PhoneCallAccepted.h"
#include "Types/COMMON/Public/PhoneCall.h"
#include "Types/COMMON/Public/PhoneCallDiscarded.h"
#include "Types/COMMON/Public/PhoneConnection.h"
#include "Types/COMMON/Public/PhoneCallProtocol.h"
#include "Types/PHONE/Public/PhoneCall.h"
#include "Types/UPLOAD/Public/CdnFileReuploadNeeded.h"
#include "Types/UPLOAD/Public/CdnFile.h"
#include "Types/COMMON/Public/CdnPublicKey.h"
#include "Types/COMMON/Public/CdnConfig.h"
#include "Types/COMMON/Public/LangPackString.h"
#include "Types/COMMON/Public/LangPackStringPluralized.h"
#include "Types/COMMON/Public/LangPackStringDeleted.h"
#include "Types/COMMON/Public/LangPackDifference.h"
#include "Types/COMMON/Public/LangPackLanguage.h"
#include "Types/COMMON/Public/ChannelAdminRights.h"
#include "Types/COMMON/Public/ChannelBannedRights.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionChangeTitle.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionChangeAbout.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionChangeUsername.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionChangePhoto.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionToggleInvites.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionToggleSignatures.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionUpdatePinned.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionEditMessage.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionDeleteMessage.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionParticipantJoin.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionParticipantLeave.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionParticipantInvite.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionParticipantToggleBan.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionParticipantToggleAdmin.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionChangeStickerSet.h"
#include "Types/COMMON/Public/ChannelAdminLogEventActionTogglePreHistoryHidden.h"
#include "Types/COMMON/Public/ChannelAdminLogEvent.h"
#include "Types/CHANNELS/Public/AdminLogResults.h"
#include "Types/COMMON/Public/ChannelAdminLogEventsFilter.h"
#include "Types/COMMON/Public/PopularContact.h"
#include "Types/COMMON/Public/CdnFileHash.h"
#include "Types/MESSAGES/Public/FavedStickersNotModified.h"
#include "Types/MESSAGES/Public/FavedStickers.h"
#include "Types/HELP/Public/RecentMeUrls.h"
#include "Types/COMMON/Public/RecentMeUrlUser.h"
#include "Types/COMMON/Public/RecentMeUrlChat.h"
#include "Types/COMMON/Public/RecentMeUrlStickerSet.h"
#include "Types/COMMON/Public/RecentMeUrlChatInvite.h"
#include "Types/COMMON/Public/RecentMeUrlUnknown.h"
#include "Functions/COMMON/Public/InvokeAfterMsg.h"
#include "Functions/COMMON/Public/InvokeAfterMsgs.h"
#include "Functions/COMMON/Public/InitConnection.h"
#include "Functions/COMMON/Public/InvokeWithLayer.h"
#include "Functions/COMMON/Public/InvokeWithoutUpdates.h"
#include "Functions/AUTH/Public/CheckPhone.h"
#include "Functions/AUTH/Public/SendCode.h"
#include "Functions/AUTH/Public/SignUp.h"
#include "Functions/AUTH/Public/SignIn.h"
#include "Functions/AUTH/Public/LogOut.h"
#include "Functions/AUTH/Public/ResetAuthorizations.h"
#include "Functions/AUTH/Public/SendInvites.h"
#include "Functions/AUTH/Public/ExportAuthorization.h"
#include "Functions/AUTH/Public/ImportAuthorization.h"
#include "Functions/AUTH/Public/BindTempAuthKey.h"
#include "Functions/AUTH/Public/ImportBotAuthorization.h"
#include "Functions/AUTH/Public/CheckPassword.h"
#include "Functions/AUTH/Public/RequestPasswordRecovery.h"
#include "Functions/AUTH/Public/RecoverPassword.h"
#include "Functions/AUTH/Public/ResendCode.h"
#include "Functions/AUTH/Public/CancelCode.h"
#include "Functions/AUTH/Public/DropTempAuthKeys.h"
#include "Functions/ACCOUNT/Public/RegisterDevice.h"
#include "Functions/ACCOUNT/Public/UnregisterDevice.h"
#include "Functions/ACCOUNT/Public/UpdateNotifySettings.h"
#include "Functions/ACCOUNT/Public/GetNotifySettings.h"
#include "Functions/ACCOUNT/Public/ResetNotifySettings.h"
#include "Functions/ACCOUNT/Public/UpdateProfile.h"
#include "Functions/ACCOUNT/Public/UpdateStatus.h"
#include "Functions/ACCOUNT/Public/GetWallPapers.h"
#include "Functions/ACCOUNT/Public/ReportPeer.h"
#include "Functions/ACCOUNT/Public/CheckUsername.h"
#include "Functions/ACCOUNT/Public/UpdateUsername.h"
#include "Functions/ACCOUNT/Public/GetPrivacy.h"
#include "Functions/ACCOUNT/Public/SetPrivacy.h"
#include "Functions/ACCOUNT/Public/DeleteAccount.h"
#include "Functions/ACCOUNT/Public/GetAccountTTL.h"
#include "Functions/ACCOUNT/Public/SetAccountTTL.h"
#include "Functions/ACCOUNT/Public/SendChangePhoneCode.h"
#include "Functions/ACCOUNT/Public/ChangePhone.h"
#include "Functions/ACCOUNT/Public/UpdateDeviceLocked.h"
#include "Functions/ACCOUNT/Public/GetAuthorizations.h"
#include "Functions/ACCOUNT/Public/ResetAuthorization.h"
#include "Functions/ACCOUNT/Public/GetPassword.h"
#include "Functions/ACCOUNT/Public/GetPasswordSettings.h"
#include "Functions/ACCOUNT/Public/UpdatePasswordSettings.h"
#include "Functions/ACCOUNT/Public/SendConfirmPhoneCode.h"
#include "Functions/ACCOUNT/Public/ConfirmPhone.h"
#include "Functions/ACCOUNT/Public/GetTmpPassword.h"
#include "Functions/USERS/Public/GetUsers.h"
#include "Functions/USERS/Public/GetFullUser.h"
#include "Functions/CONTACTS/Public/GetStatuses.h"
#include "Functions/CONTACTS/Public/GetContacts.h"
#include "Functions/CONTACTS/Public/ImportContacts.h"
#include "Functions/CONTACTS/Public/DeleteContact.h"
#include "Functions/CONTACTS/Public/DeleteContacts.h"
#include "Functions/CONTACTS/Public/Block.h"
#include "Functions/CONTACTS/Public/Unblock.h"
#include "Functions/CONTACTS/Public/GetBlocked.h"
#include "Functions/CONTACTS/Public/ExportCard.h"
#include "Functions/CONTACTS/Public/ImportCard.h"
#include "Functions/CONTACTS/Public/Search.h"
#include "Functions/CONTACTS/Public/ResolveUsername.h"
#include "Functions/CONTACTS/Public/GetTopPeers.h"
#include "Functions/CONTACTS/Public/ResetTopPeerRating.h"
#include "Functions/CONTACTS/Public/ResetSaved.h"
#include "Functions/MESSAGES/Public/GetMessages.h"
#include "Functions/MESSAGES/Public/GetDialogs.h"
#include "Functions/MESSAGES/Public/GetHistory.h"
#include "Functions/MESSAGES/Public/Search.h"
#include "Functions/MESSAGES/Public/ReadHistory.h"
#include "Functions/MESSAGES/Public/DeleteHistory.h"
#include "Functions/MESSAGES/Public/DeleteMessages.h"
#include "Functions/MESSAGES/Public/ReceivedMessages.h"
#include "Functions/MESSAGES/Public/SetTyping.h"
#include "Functions/MESSAGES/Public/SendMessage.h"
#include "Functions/MESSAGES/Public/SendMedia.h"
#include "Functions/MESSAGES/Public/ForwardMessages.h"
#include "Functions/MESSAGES/Public/ReportSpam.h"
#include "Functions/MESSAGES/Public/HideReportSpam.h"
#include "Functions/MESSAGES/Public/GetPeerSettings.h"
#include "Functions/MESSAGES/Public/GetChats.h"
#include "Functions/MESSAGES/Public/GetFullChat.h"
#include "Functions/MESSAGES/Public/EditChatTitle.h"
#include "Functions/MESSAGES/Public/EditChatPhoto.h"
#include "Functions/MESSAGES/Public/AddChatUser.h"
#include "Functions/MESSAGES/Public/DeleteChatUser.h"
#include "Functions/MESSAGES/Public/CreateChat.h"
#include "Functions/MESSAGES/Public/ForwardMessage.h"
#include "Functions/MESSAGES/Public/GetDhConfig.h"
#include "Functions/MESSAGES/Public/RequestEncryption.h"
#include "Functions/MESSAGES/Public/AcceptEncryption.h"
#include "Functions/MESSAGES/Public/DiscardEncryption.h"
#include "Functions/MESSAGES/Public/SetEncryptedTyping.h"
#include "Functions/MESSAGES/Public/ReadEncryptedHistory.h"
#include "Functions/MESSAGES/Public/SendEncrypted.h"
#include "Functions/MESSAGES/Public/SendEncryptedFile.h"
#include "Functions/MESSAGES/Public/SendEncryptedService.h"
#include "Functions/MESSAGES/Public/ReceivedQueue.h"
#include "Functions/MESSAGES/Public/ReportEncryptedSpam.h"
#include "Functions/MESSAGES/Public/ReadMessageContents.h"
#include "Functions/MESSAGES/Public/GetAllStickers.h"
#include "Functions/MESSAGES/Public/GetWebPagePreview.h"
#include "Functions/MESSAGES/Public/ExportChatInvite.h"
#include "Functions/MESSAGES/Public/CheckChatInvite.h"
#include "Functions/MESSAGES/Public/ImportChatInvite.h"
#include "Functions/MESSAGES/Public/GetStickerSet.h"
#include "Functions/MESSAGES/Public/InstallStickerSet.h"
#include "Functions/MESSAGES/Public/UninstallStickerSet.h"
#include "Functions/MESSAGES/Public/StartBot.h"
#include "Functions/MESSAGES/Public/GetMessagesViews.h"
#include "Functions/MESSAGES/Public/ToggleChatAdmins.h"
#include "Functions/MESSAGES/Public/EditChatAdmin.h"
#include "Functions/MESSAGES/Public/MigrateChat.h"
#include "Functions/MESSAGES/Public/SearchGlobal.h"
#include "Functions/MESSAGES/Public/ReorderStickerSets.h"
#include "Functions/MESSAGES/Public/GetDocumentByHash.h"
#include "Functions/MESSAGES/Public/SearchGifs.h"
#include "Functions/MESSAGES/Public/GetSavedGifs.h"
#include "Functions/MESSAGES/Public/SaveGif.h"
#include "Functions/MESSAGES/Public/GetInlineBotResults.h"
#include "Functions/MESSAGES/Public/SetInlineBotResults.h"
#include "Functions/MESSAGES/Public/SendInlineBotResult.h"
#include "Functions/MESSAGES/Public/GetMessageEditData.h"
#include "Functions/MESSAGES/Public/EditMessage.h"
#include "Functions/MESSAGES/Public/EditInlineBotMessage.h"
#include "Functions/MESSAGES/Public/GetBotCallbackAnswer.h"
#include "Functions/MESSAGES/Public/SetBotCallbackAnswer.h"
#include "Functions/MESSAGES/Public/GetPeerDialogs.h"
#include "Functions/MESSAGES/Public/SaveDraft.h"
#include "Functions/MESSAGES/Public/GetAllDrafts.h"
#include "Functions/MESSAGES/Public/GetFeaturedStickers.h"
#include "Functions/MESSAGES/Public/ReadFeaturedStickers.h"
#include "Functions/MESSAGES/Public/GetRecentStickers.h"
#include "Functions/MESSAGES/Public/SaveRecentSticker.h"
#include "Functions/MESSAGES/Public/ClearRecentStickers.h"
#include "Functions/MESSAGES/Public/GetArchivedStickers.h"
#include "Functions/MESSAGES/Public/GetMaskStickers.h"
#include "Functions/MESSAGES/Public/GetAttachedStickers.h"
#include "Functions/MESSAGES/Public/SetGameScore.h"
#include "Functions/MESSAGES/Public/SetInlineGameScore.h"
#include "Functions/MESSAGES/Public/GetGameHighScores.h"
#include "Functions/MESSAGES/Public/GetInlineGameHighScores.h"
#include "Functions/MESSAGES/Public/GetCommonChats.h"
#include "Functions/MESSAGES/Public/GetAllChats.h"
#include "Functions/MESSAGES/Public/GetWebPage.h"
#include "Functions/MESSAGES/Public/ToggleDialogPin.h"
#include "Functions/MESSAGES/Public/ReorderPinnedDialogs.h"
#include "Functions/MESSAGES/Public/GetPinnedDialogs.h"
#include "Functions/MESSAGES/Public/SetBotShippingResults.h"
#include "Functions/MESSAGES/Public/SetBotPrecheckoutResults.h"
#include "Functions/MESSAGES/Public/UploadMedia.h"
#include "Functions/MESSAGES/Public/SendScreenshotNotification.h"
#include "Functions/MESSAGES/Public/GetFavedStickers.h"
#include "Functions/MESSAGES/Public/FaveSticker.h"
#include "Functions/MESSAGES/Public/GetUnreadMentions.h"
#include "Functions/MESSAGES/Public/GetRecentLocations.h"
#include "Functions/MESSAGES/Public/ReadMentions.h"
#include "Functions/UPDATES/Public/GetState.h"
#include "Functions/UPDATES/Public/GetDifference.h"
#include "Functions/UPDATES/Public/GetChannelDifference.h"
#include "Functions/PHOTOS/Public/UpdateProfilePhoto.h"
#include "Functions/PHOTOS/Public/UploadProfilePhoto.h"
#include "Functions/PHOTOS/Public/DeletePhotos.h"
#include "Functions/PHOTOS/Public/GetUserPhotos.h"
#include "Functions/UPLOAD/Public/SaveFilePart.h"
#include "Functions/UPLOAD/Public/GetFile.h"
#include "Functions/UPLOAD/Public/SaveBigFilePart.h"
#include "Functions/UPLOAD/Public/GetWebFile.h"
#include "Functions/UPLOAD/Public/GetCdnFile.h"
#include "Functions/UPLOAD/Public/ReuploadCdnFile.h"
#include "Functions/UPLOAD/Public/GetCdnFileHashes.h"
#include "Functions/HELP/Public/GetConfig.h"
#include "Functions/HELP/Public/GetNearestDc.h"
#include "Functions/HELP/Public/GetAppUpdate.h"
#include "Functions/HELP/Public/SaveAppLog.h"
#include "Functions/HELP/Public/GetInviteText.h"
#include "Functions/HELP/Public/GetSupport.h"
#include "Functions/HELP/Public/GetAppChangelog.h"
#include "Functions/HELP/Public/GetTermsOfService.h"
#include "Functions/HELP/Public/SetBotUpdatesStatus.h"
#include "Functions/HELP/Public/GetCdnConfig.h"
#include "Functions/HELP/Public/GetRecentMeUrls.h"
#include "Functions/CHANNELS/Public/ReadHistory.h"
#include "Functions/CHANNELS/Public/DeleteMessages.h"
#include "Functions/CHANNELS/Public/DeleteUserHistory.h"
#include "Functions/CHANNELS/Public/ReportSpam.h"
#include "Functions/CHANNELS/Public/GetMessages.h"
#include "Functions/CHANNELS/Public/GetParticipants.h"
#include "Functions/CHANNELS/Public/GetParticipant.h"
#include "Functions/CHANNELS/Public/GetChannels.h"
#include "Functions/CHANNELS/Public/GetFullChannel.h"
#include "Functions/CHANNELS/Public/CreateChannel.h"
#include "Functions/CHANNELS/Public/EditAbout.h"
#include "Functions/CHANNELS/Public/EditAdmin.h"
#include "Functions/CHANNELS/Public/EditTitle.h"
#include "Functions/CHANNELS/Public/EditPhoto.h"
#include "Functions/CHANNELS/Public/CheckUsername.h"
#include "Functions/CHANNELS/Public/UpdateUsername.h"
#include "Functions/CHANNELS/Public/JoinChannel.h"
#include "Functions/CHANNELS/Public/LeaveChannel.h"
#include "Functions/CHANNELS/Public/InviteToChannel.h"
#include "Functions/CHANNELS/Public/ExportInvite.h"
#include "Functions/CHANNELS/Public/DeleteChannel.h"
#include "Functions/CHANNELS/Public/ToggleInvites.h"
#include "Functions/CHANNELS/Public/ExportMessageLink.h"
#include "Functions/CHANNELS/Public/ToggleSignatures.h"
#include "Functions/CHANNELS/Public/UpdatePinnedMessage.h"
#include "Functions/CHANNELS/Public/GetAdminedPublicChannels.h"
#include "Functions/CHANNELS/Public/EditBanned.h"
#include "Functions/CHANNELS/Public/GetAdminLog.h"
#include "Functions/CHANNELS/Public/SetStickers.h"
#include "Functions/CHANNELS/Public/ReadMessageContents.h"
#include "Functions/CHANNELS/Public/DeleteHistory.h"
#include "Functions/CHANNELS/Public/TogglePreHistoryHidden.h"
#include "Functions/BOTS/Public/SendCustomRequest.h"
#include "Functions/BOTS/Public/AnswerWebhookJSONQuery.h"
#include "Functions/PAYMENTS/Public/GetPaymentForm.h"
#include "Functions/PAYMENTS/Public/GetPaymentReceipt.h"
#include "Functions/PAYMENTS/Public/ValidateRequestedInfo.h"
#include "Functions/PAYMENTS/Public/SendPaymentForm.h"
#include "Functions/PAYMENTS/Public/GetSavedInfo.h"
#include "Functions/PAYMENTS/Public/ClearSavedInfo.h"
#include "Functions/STICKERS/Public/CreateStickerSet.h"
#include "Functions/STICKERS/Public/RemoveStickerFromSet.h"
#include "Functions/STICKERS/Public/ChangeStickerPosition.h"
#include "Functions/STICKERS/Public/AddStickerToSet.h"
#include "Functions/PHONE/Public/GetCallConfig.h"
#include "Functions/PHONE/Public/RequestCall.h"
#include "Functions/PHONE/Public/AcceptCall.h"
#include "Functions/PHONE/Public/ConfirmCall.h"
#include "Functions/PHONE/Public/ReceivedCall.h"
#include "Functions/PHONE/Public/DiscardCall.h"
#include "Functions/PHONE/Public/SetCallRating.h"
#include "Functions/PHONE/Public/SaveCallDebug.h"
#include "Functions/LANGPACK/Public/GetLangPack.h"
#include "Functions/LANGPACK/Public/GetStrings.h"
#include "Functions/LANGPACK/Public/GetDifference.h"
#include "Functions/LANGPACK/Public/GetLanguages.h"


TLBaseObject* TLObjects(uint32 ConstructorID)
{
	switch(ConstructorID)
	{
		case 85337187: 
		{
			return new COMMON::ResPQ();
		break;
		}
		case 2211011308: 
		{
			return new COMMON::PQInnerData();
		break;
		}
		case 2043348061: 
		{
			return new COMMON::ServerDHParamsFail();
		break;
		}
		case 3504867164: 
		{
			return new COMMON::ServerDHParamsOk();
		break;
		}
		case 3045658042: 
		{
			return new COMMON::ServerDHInnerData();
		break;
		}
		case 1715713620: 
		{
			return new COMMON::ClientDHInnerData();
		break;
		}
		case 1003222836: 
		{
			return new COMMON::DhGenOk();
		break;
		}
		case 1188831161: 
		{
			return new COMMON::DhGenRetry();
		break;
		}
		case 2795351554: 
		{
			return new COMMON::DhGenFail();
		break;
		}
		case 4133544404: 
		{
			return new COMMON::DestroyAuthKeyOk();
		break;
		}
		case 178201177: 
		{
			return new COMMON::DestroyAuthKeyNone();
		break;
		}
		case 3926956819: 
		{
			return new COMMON::DestroyAuthKeyFail();
		break;
		}
		case 1615239032: 
		{
			return new COMMON::ReqPq();
		break;
		}
		case 3608339646: 
		{
			return new COMMON::ReqDHParams();
		break;
		}
		case 4110704415: 
		{
			return new COMMON::SetClientDHParams();
		break;
		}
		case 3510849888: 
		{
			return new COMMON::DestroyAuthKey();
		break;
		}
		case 1658238041: 
		{
			return new COMMON::MsgsAck();
		break;
		}
		case 2817521681: 
		{
			return new COMMON::BadMsgNotification();
		break;
		}
		case 3987424379: 
		{
			return new COMMON::BadServerSalt();
		break;
		}
		case 3664378706: 
		{
			return new COMMON::MsgsStateReq();
		break;
		}
		case 81704317: 
		{
			return new COMMON::MsgsStateInfo();
		break;
		}
		case 2361446705: 
		{
			return new COMMON::MsgsAllInfo();
		break;
		}
		case 661470918: 
		{
			return new COMMON::MsgDetailedInfo();
		break;
		}
		case 2157819615: 
		{
			return new COMMON::MsgNewDetailedInfo();
		break;
		}
		case 2105940488: 
		{
			return new COMMON::MsgResendReq();
		break;
		}
		case 558156313: 
		{
			return new COMMON::RpcError();
		break;
		}
		case 1579864942: 
		{
			return new COMMON::RpcAnswerUnknown();
		break;
		}
		case 3447252358: 
		{
			return new COMMON::RpcAnswerDroppedRunning();
		break;
		}
		case 2755319991: 
		{
			return new COMMON::RpcAnswerDropped();
		break;
		}
		case 155834844: 
		{
			return new COMMON::FutureSalt();
		break;
		}
		case 2924480661: 
		{
			return new COMMON::FutureSalts();
		break;
		}
		case 880243653: 
		{
			return new COMMON::Pong();
		break;
		}
		case 3793765884: 
		{
			return new COMMON::DestroySessionOk();
		break;
		}
		case 1658015945: 
		{
			return new COMMON::DestroySessionNone();
		break;
		}
		case 2663516424: 
		{
			return new COMMON::NewSessionCreated();
		break;
		}
		case 2459514271: 
		{
			return new COMMON::HttpWait();
		break;
		}
		case 3560156531: 
		{
			return new COMMON::IpPort();
		break;
		}
		case 3650601925: 
		{
			return new HELP::ConfigSimple();
		break;
		}
		case 1491380032: 
		{
			return new COMMON::RpcDropAnswer();
		break;
		}
		case 3105996036: 
		{
			return new COMMON::GetFutureSalts();
		break;
		}
		case 2059302892: 
		{
			return new COMMON::Ping();
		break;
		}
		case 4081220492: 
		{
			return new COMMON::PingDelayDisconnect();
		break;
		}
		case 3880853798: 
		{
			return new COMMON::DestroySession();
		break;
		}
		case 2589945493: 
		{
			return new CONTEST::SaveDeveloperInfo();
		break;
		}
		case 3162085175: 
		{
			return new COMMON::BoolFalse();
		break;
		}
		case 2574415285: 
		{
			return new COMMON::BoolTrue();
		break;
		}
		case 1072550713: 
		{
			return new COMMON::True();
		break;
		}
		case 3300522427: 
		{
			return new COMMON::Error();
		break;
		}
		case 1450380236: 
		{
			return new COMMON::Null();
		break;
		}
		case 2134579434: 
		{
			return new COMMON::InputPeerEmpty();
		break;
		}
		case 2107670217: 
		{
			return new COMMON::InputPeerSelf();
		break;
		}
		case 396093539: 
		{
			return new COMMON::InputPeerChat();
		break;
		}
		case 2072935910: 
		{
			return new COMMON::InputPeerUser();
		break;
		}
		case 548253432: 
		{
			return new COMMON::InputPeerChannel();
		break;
		}
		case 3112732367: 
		{
			return new COMMON::InputUserEmpty();
		break;
		}
		case 4156666175: 
		{
			return new COMMON::InputUserSelf();
		break;
		}
		case 3626575894: 
		{
			return new COMMON::InputUser();
		break;
		}
		case 4086478836: 
		{
			return new COMMON::InputPhoneContact();
		break;
		}
		case 4113560191: 
		{
			return new COMMON::InputFile();
		break;
		}
		case 4199484341: 
		{
			return new COMMON::InputFileBig();
		break;
		}
		case 2523198847: 
		{
			return new COMMON::InputMediaEmpty();
		break;
		}
		case 792191537: 
		{
			return new COMMON::InputMediaUploadedPhoto();
		break;
		}
		case 2180659002: 
		{
			return new COMMON::InputMediaPhoto();
		break;
		}
		case 4190388548: 
		{
			return new COMMON::InputMediaGeoPoint();
		break;
		}
		case 2799982983: 
		{
			return new COMMON::InputMediaContact();
		break;
		}
		case 3818267133: 
		{
			return new COMMON::InputMediaUploadedDocument();
		break;
		}
		case 1523279502: 
		{
			return new COMMON::InputMediaDocument();
		break;
		}
		case 3242007569: 
		{
			return new COMMON::InputMediaVenue();
		break;
		}
		case 1212395773: 
		{
			return new COMMON::InputMediaGifExternal();
		break;
		}
		case 153267905: 
		{
			return new COMMON::InputMediaPhotoExternal();
		break;
		}
		case 3069657909: 
		{
			return new COMMON::InputMediaDocumentExternal();
		break;
		}
		case 3544138739: 
		{
			return new COMMON::InputMediaGame();
		break;
		}
		case 2450863749: 
		{
			return new COMMON::InputMediaInvoice();
		break;
		}
		case 2065305999: 
		{
			return new COMMON::InputMediaGeoLive();
		break;
		}
		case 480546647: 
		{
			return new COMMON::InputChatPhotoEmpty();
		break;
		}
		case 2457621940: 
		{
			return new COMMON::InputChatUploadedPhoto();
		break;
		}
		case 2303962423: 
		{
			return new COMMON::InputChatPhoto();
		break;
		}
		case 3837862870: 
		{
			return new COMMON::InputGeoPointEmpty();
		break;
		}
		case 4088900809: 
		{
			return new COMMON::InputGeoPoint();
		break;
		}
		case 483901197: 
		{
			return new COMMON::InputPhotoEmpty();
		break;
		}
		case 4220896964: 
		{
			return new COMMON::InputPhoto();
		break;
		}
		case 342061462: 
		{
			return new COMMON::InputFileLocation();
		break;
		}
		case 4112735573: 
		{
			return new COMMON::InputEncryptedFileLocation();
		break;
		}
		case 1125058340: 
		{
			return new COMMON::InputDocumentFileLocation();
		break;
		}
		case 1996904104: 
		{
			return new COMMON::InputAppEvent();
		break;
		}
		case 2645671021: 
		{
			return new COMMON::PeerUser();
		break;
		}
		case 3134252475: 
		{
			return new COMMON::PeerChat();
		break;
		}
		case 3185435954: 
		{
			return new COMMON::PeerChannel();
		break;
		}
		case 2861972229: 
		{
			return new STORAGE::FileUnknown();
		break;
		}
		case 1086091090: 
		{
			return new STORAGE::FilePartial();
		break;
		}
		case 8322574: 
		{
			return new STORAGE::FileJpeg();
		break;
		}
		case 3403786975: 
		{
			return new STORAGE::FileGif();
		break;
		}
		case 172975040: 
		{
			return new STORAGE::FilePng();
		break;
		}
		case 2921222285: 
		{
			return new STORAGE::FilePdf();
		break;
		}
		case 1384777335: 
		{
			return new STORAGE::FileMp3();
		break;
		}
		case 1258941372: 
		{
			return new STORAGE::FileMov();
		break;
		}
		case 3016663268: 
		{
			return new STORAGE::FileMp4();
		break;
		}
		case 276907596: 
		{
			return new STORAGE::FileWebp();
		break;
		}
		case 2086234950: 
		{
			return new COMMON::FileLocationUnavailable();
		break;
		}
		case 1406570614: 
		{
			return new COMMON::FileLocation();
		break;
		}
		case 537022650: 
		{
			return new COMMON::UserEmpty();
		break;
		}
		case 773059779: 
		{
			return new COMMON::User();
		break;
		}
		case 1326562017: 
		{
			return new COMMON::UserProfilePhotoEmpty();
		break;
		}
		case 3579435208: 
		{
			return new COMMON::UserProfilePhoto();
		break;
		}
		case 164646985: 
		{
			return new COMMON::UserStatusEmpty();
		break;
		}
		case 3988339017: 
		{
			return new COMMON::UserStatusOnline();
		break;
		}
		case 9203775: 
		{
			return new COMMON::UserStatusOffline();
		break;
		}
		case 3798942449: 
		{
			return new COMMON::UserStatusRecently();
		break;
		}
		case 129960444: 
		{
			return new COMMON::UserStatusLastWeek();
		break;
		}
		case 2011940674: 
		{
			return new COMMON::UserStatusLastMonth();
		break;
		}
		case 2611140608: 
		{
			return new COMMON::ChatEmpty();
		break;
		}
		case 3642547540: 
		{
			return new COMMON::Chat();
		break;
		}
		case 120753115: 
		{
			return new COMMON::ChatForbidden();
		break;
		}
		case 213142300: 
		{
			return new COMMON::Channel();
		break;
		}
		case 681420594: 
		{
			return new COMMON::ChannelForbidden();
		break;
		}
		case 771925524: 
		{
			return new COMMON::ChatFull();
		break;
		}
		case 1991201921: 
		{
			return new COMMON::ChannelFull();
		break;
		}
		case 3369552190: 
		{
			return new COMMON::ChatParticipant();
		break;
		}
		case 3658699658: 
		{
			return new COMMON::ChatParticipantCreator();
		break;
		}
		case 3805733942: 
		{
			return new COMMON::ChatParticipantAdmin();
		break;
		}
		case 4237298731: 
		{
			return new COMMON::ChatParticipantsForbidden();
		break;
		}
		case 1061556205: 
		{
			return new COMMON::ChatParticipants();
		break;
		}
		case 935395612: 
		{
			return new COMMON::ChatPhotoEmpty();
		break;
		}
		case 1632839530: 
		{
			return new COMMON::ChatPhoto();
		break;
		}
		case 2212879956: 
		{
			return new COMMON::MessageEmpty();
		break;
		}
		case 2430458897: 
		{
			return new COMMON::Message();
		break;
		}
		case 2652479990: 
		{
			return new COMMON::MessageService();
		break;
		}
		case 1038967584: 
		{
			return new COMMON::MessageMediaEmpty();
		break;
		}
		case 3038919439: 
		{
			return new COMMON::MessageMediaPhoto();
		break;
		}
		case 1457575028: 
		{
			return new COMMON::MessageMediaGeo();
		break;
		}
		case 1585262393: 
		{
			return new COMMON::MessageMediaContact();
		break;
		}
		case 2676290718: 
		{
			return new COMMON::MessageMediaUnsupported();
		break;
		}
		case 2084836563: 
		{
			return new COMMON::MessageMediaDocument();
		break;
		}
		case 2737690112: 
		{
			return new COMMON::MessageMediaWebPage();
		break;
		}
		case 784356159: 
		{
			return new COMMON::MessageMediaVenue();
		break;
		}
		case 4256272392: 
		{
			return new COMMON::MessageMediaGame();
		break;
		}
		case 2220168007: 
		{
			return new COMMON::MessageMediaInvoice();
		break;
		}
		case 2084316681: 
		{
			return new COMMON::MessageMediaGeoLive();
		break;
		}
		case 3064919984: 
		{
			return new COMMON::MessageActionEmpty();
		break;
		}
		case 2791541658: 
		{
			return new COMMON::MessageActionChatCreate();
		break;
		}
		case 3047280218: 
		{
			return new COMMON::MessageActionChatEditTitle();
		break;
		}
		case 2144015272: 
		{
			return new COMMON::MessageActionChatEditPhoto();
		break;
		}
		case 2514746351: 
		{
			return new COMMON::MessageActionChatDeletePhoto();
		break;
		}
		case 1217033015: 
		{
			return new COMMON::MessageActionChatAddUser();
		break;
		}
		case 2997787404: 
		{
			return new COMMON::MessageActionChatDeleteUser();
		break;
		}
		case 4171036136: 
		{
			return new COMMON::MessageActionChatJoinedByLink();
		break;
		}
		case 2513611922: 
		{
			return new COMMON::MessageActionChannelCreate();
		break;
		}
		case 1371385889: 
		{
			return new COMMON::MessageActionChatMigrateTo();
		break;
		}
		case 2958420718: 
		{
			return new COMMON::MessageActionChannelMigrateFrom();
		break;
		}
		case 2495428845: 
		{
			return new COMMON::MessageActionPinMessage();
		break;
		}
		case 2679813636: 
		{
			return new COMMON::MessageActionHistoryClear();
		break;
		}
		case 2460428406: 
		{
			return new COMMON::MessageActionGameScore();
		break;
		}
		case 2402399015: 
		{
			return new COMMON::MessageActionPaymentSentMe();
		break;
		}
		case 1080663248: 
		{
			return new COMMON::MessageActionPaymentSent();
		break;
		}
		case 2162236031: 
		{
			return new COMMON::MessageActionPhoneCall();
		break;
		}
		case 1200788123: 
		{
			return new COMMON::MessageActionScreenshotTaken();
		break;
		}
		case 4209418070: 
		{
			return new COMMON::MessageActionCustomAction();
		break;
		}
		case 3839817179: 
		{
			return new COMMON::Dialog();
		break;
		}
		case 590459437: 
		{
			return new COMMON::PhotoEmpty();
		break;
		}
		case 2458443049: 
		{
			return new COMMON::Photo();
		break;
		}
		case 236446268: 
		{
			return new COMMON::PhotoSizeEmpty();
		break;
		}
		case 2009052699: 
		{
			return new COMMON::PhotoSize();
		break;
		}
		case 3920049402: 
		{
			return new COMMON::PhotoCachedSize();
		break;
		}
		case 286776671: 
		{
			return new COMMON::GeoPointEmpty();
		break;
		}
		case 541710092: 
		{
			return new COMMON::GeoPoint();
		break;
		}
		case 2166268558: 
		{
			return new AUTH::CheckedPhone();
		break;
		}
		case 1577067778: 
		{
			return new AUTH::SentCode();
		break;
		}
		case 3439659286: 
		{
			return new AUTH::Authorization();
		break;
		}
		case 3751189549: 
		{
			return new AUTH::ExportedAuthorization();
		break;
		}
		case 3099351820: 
		{
			return new COMMON::InputNotifyPeer();
		break;
		}
		case 423314455: 
		{
			return new COMMON::InputNotifyUsers();
		break;
		}
		case 1251338318: 
		{
			return new COMMON::InputNotifyChats();
		break;
		}
		case 2754197638: 
		{
			return new COMMON::InputNotifyAll();
		break;
		}
		case 4029703384: 
		{
			return new COMMON::InputPeerNotifyEventsEmpty();
		break;
		}
		case 3899272308: 
		{
			return new COMMON::InputPeerNotifyEventsAll();
		break;
		}
		case 949182130: 
		{
			return new COMMON::InputPeerNotifySettings();
		break;
		}
		case 2916433075: 
		{
			return new COMMON::PeerNotifyEventsEmpty();
		break;
		}
		case 1830677896: 
		{
			return new COMMON::PeerNotifyEventsAll();
		break;
		}
		case 1889961234: 
		{
			return new COMMON::PeerNotifySettingsEmpty();
		break;
		}
		case 2597168320: 
		{
			return new COMMON::PeerNotifySettings();
		break;
		}
		case 2172921549: 
		{
			return new COMMON::PeerSettings();
		break;
		}
		case 3434100311: 
		{
			return new COMMON::WallPaper();
		break;
		}
		case 1662091044: 
		{
			return new COMMON::WallPaperSolid();
		break;
		}
		case 1490799288: 
		{
			return new COMMON::InputReportReasonSpam();
		break;
		}
		case 505595789: 
		{
			return new COMMON::InputReportReasonViolence();
		break;
		}
		case 777640226: 
		{
			return new COMMON::InputReportReasonPornography();
		break;
		}
		case 3782503690: 
		{
			return new COMMON::InputReportReasonOther();
		break;
		}
		case 253890367: 
		{
			return new COMMON::UserFull();
		break;
		}
		case 4178692500: 
		{
			return new COMMON::Contact();
		break;
		}
		case 3489825848: 
		{
			return new COMMON::ImportedContact();
		break;
		}
		case 1444661369: 
		{
			return new COMMON::ContactBlocked();
		break;
		}
		case 3546811489: 
		{
			return new COMMON::ContactStatus();
		break;
		}
		case 986597452: 
		{
			return new CONTACTS::Link();
		break;
		}
		case 3075189202: 
		{
			return new CONTACTS::ContactsNotModified();
		break;
		}
		case 3941105218: 
		{
			return new CONTACTS::Contacts();
		break;
		}
		case 2010127419: 
		{
			return new CONTACTS::ImportedContacts();
		break;
		}
		case 471043349: 
		{
			return new CONTACTS::Blocked();
		break;
		}
		case 2416444065: 
		{
			return new CONTACTS::BlockedSlice();
		break;
		}
		case 364538944: 
		{
			return new MESSAGES::Dialogs();
		break;
		}
		case 1910543603: 
		{
			return new MESSAGES::DialogsSlice();
		break;
		}
		case 2356252295: 
		{
			return new MESSAGES::Messages();
		break;
		}
		case 189033187: 
		{
			return new MESSAGES::MessagesSlice();
		break;
		}
		case 2569416247: 
		{
			return new MESSAGES::ChannelMessages();
		break;
		}
		case 1694474197: 
		{
			return new MESSAGES::Chats();
		break;
		}
		case 2631405892: 
		{
			return new MESSAGES::ChatsSlice();
		break;
		}
		case 3856126364: 
		{
			return new MESSAGES::ChatFull();
		break;
		}
		case 3025955281: 
		{
			return new MESSAGES::AffectedHistory();
		break;
		}
		case 1474492012: 
		{
			return new COMMON::InputMessagesFilterEmpty();
		break;
		}
		case 2517214492: 
		{
			return new COMMON::InputMessagesFilterPhotos();
		break;
		}
		case 2680163941: 
		{
			return new COMMON::InputMessagesFilterVideo();
		break;
		}
		case 1458172132: 
		{
			return new COMMON::InputMessagesFilterPhotoVideo();
		break;
		}
		case 3646845883: 
		{
			return new COMMON::InputMessagesFilterPhotoVideoDocuments();
		break;
		}
		case 2665345416: 
		{
			return new COMMON::InputMessagesFilterDocument();
		break;
		}
		case 2129714567: 
		{
			return new COMMON::InputMessagesFilterUrl();
		break;
		}
		case 4291323271: 
		{
			return new COMMON::InputMessagesFilterGif();
		break;
		}
		case 1358283666: 
		{
			return new COMMON::InputMessagesFilterVoice();
		break;
		}
		case 928101534: 
		{
			return new COMMON::InputMessagesFilterMusic();
		break;
		}
		case 975236280: 
		{
			return new COMMON::InputMessagesFilterChatPhotos();
		break;
		}
		case 2160695144: 
		{
			return new COMMON::InputMessagesFilterPhoneCalls();
		break;
		}
		case 2054952868: 
		{
			return new COMMON::InputMessagesFilterRoundVoice();
		break;
		}
		case 3041516115: 
		{
			return new COMMON::InputMessagesFilterRoundVideo();
		break;
		}
		case 3254314650: 
		{
			return new COMMON::InputMessagesFilterMyMentions();
		break;
		}
		case 3764575107: 
		{
			return new COMMON::InputMessagesFilterContacts();
		break;
		}
		case 3875695885: 
		{
			return new COMMON::InputMessagesFilterGeo();
		break;
		}
		case 522914557: 
		{
			return new COMMON::UpdateNewMessage();
		break;
		}
		case 1318109142: 
		{
			return new COMMON::UpdateMessageID();
		break;
		}
		case 2718806245: 
		{
			return new COMMON::UpdateDeleteMessages();
		break;
		}
		case 1548249383: 
		{
			return new COMMON::UpdateUserTyping();
		break;
		}
		case 2590370335: 
		{
			return new COMMON::UpdateChatUserTyping();
		break;
		}
		case 125178264: 
		{
			return new COMMON::UpdateChatParticipants();
		break;
		}
		case 469489699: 
		{
			return new COMMON::UpdateUserStatus();
		break;
		}
		case 2805148531: 
		{
			return new COMMON::UpdateUserName();
		break;
		}
		case 2503031564: 
		{
			return new COMMON::UpdateUserPhoto();
		break;
		}
		case 628472761: 
		{
			return new COMMON::UpdateContactRegistered();
		break;
		}
		case 2637064133: 
		{
			return new COMMON::UpdateContactLink();
		break;
		}
		case 314359194: 
		{
			return new COMMON::UpdateNewEncryptedMessage();
		break;
		}
		case 386986326: 
		{
			return new COMMON::UpdateEncryptedChatTyping();
		break;
		}
		case 3030575245: 
		{
			return new COMMON::UpdateEncryption();
		break;
		}
		case 956179895: 
		{
			return new COMMON::UpdateEncryptedMessagesRead();
		break;
		}
		case 3930787420: 
		{
			return new COMMON::UpdateChatParticipantAdd();
		break;
		}
		case 1851755554: 
		{
			return new COMMON::UpdateChatParticipantDelete();
		break;
		}
		case 2388564083: 
		{
			return new COMMON::UpdateDcOptions();
		break;
		}
		case 2163009562: 
		{
			return new COMMON::UpdateUserBlocked();
		break;
		}
		case 3200411887: 
		{
			return new COMMON::UpdateNotifySettings();
		break;
		}
		case 3957614617: 
		{
			return new COMMON::UpdateServiceNotification();
		break;
		}
		case 3996854058: 
		{
			return new COMMON::UpdatePrivacy();
		break;
		}
		case 314130811: 
		{
			return new COMMON::UpdateUserPhone();
		break;
		}
		case 2573335900: 
		{
			return new COMMON::UpdateReadHistoryInbox();
		break;
		}
		case 791617983: 
		{
			return new COMMON::UpdateReadHistoryOutbox();
		break;
		}
		case 2139689491: 
		{
			return new COMMON::UpdateWebPage();
		break;
		}
		case 1757493555: 
		{
			return new COMMON::UpdateReadMessagesContents();
		break;
		}
		case 3942934523: 
		{
			return new COMMON::UpdateChannelTooLong();
		break;
		}
		case 3067369046: 
		{
			return new COMMON::UpdateChannel();
		break;
		}
		case 1656358105: 
		{
			return new COMMON::UpdateNewChannelMessage();
		break;
		}
		case 1108669311: 
		{
			return new COMMON::UpdateReadChannelInbox();
		break;
		}
		case 3279233481: 
		{
			return new COMMON::UpdateDeleteChannelMessages();
		break;
		}
		case 2560699211: 
		{
			return new COMMON::UpdateChannelMessageViews();
		break;
		}
		case 1855224129: 
		{
			return new COMMON::UpdateChatAdmins();
		break;
		}
		case 3062896985: 
		{
			return new COMMON::UpdateChatParticipantAdmin();
		break;
		}
		case 1753886890: 
		{
			return new COMMON::UpdateNewStickerSet();
		break;
		}
		case 196268545: 
		{
			return new COMMON::UpdateStickerSetsOrder();
		break;
		}
		case 1135492588: 
		{
			return new COMMON::UpdateStickerSets();
		break;
		}
		case 2473931806: 
		{
			return new COMMON::UpdateSavedGifs();
		break;
		}
		case 1417832080: 
		{
			return new COMMON::UpdateBotInlineQuery();
		break;
		}
		case 239663460: 
		{
			return new COMMON::UpdateBotInlineSend();
		break;
		}
		case 457133559: 
		{
			return new COMMON::UpdateEditChannelMessage();
		break;
		}
		case 2555978869: 
		{
			return new COMMON::UpdateChannelPinnedMessage();
		break;
		}
		case 3879028705: 
		{
			return new COMMON::UpdateBotCallbackQuery();
		break;
		}
		case 3825430691: 
		{
			return new COMMON::UpdateEditMessage();
		break;
		}
		case 4191320666: 
		{
			return new COMMON::UpdateInlineBotCallbackQuery();
		break;
		}
		case 634833351: 
		{
			return new COMMON::UpdateReadChannelOutbox();
		break;
		}
		case 3995842921: 
		{
			return new COMMON::UpdateDraftMessage();
		break;
		}
		case 1461528386: 
		{
			return new COMMON::UpdateReadFeaturedStickers();
		break;
		}
		case 2588027936: 
		{
			return new COMMON::UpdateRecentStickers();
		break;
		}
		case 2720652550: 
		{
			return new COMMON::UpdateConfig();
		break;
		}
		case 861169551: 
		{
			return new COMMON::UpdatePtsChanged();
		break;
		}
		case 1081547008: 
		{
			return new COMMON::UpdateChannelWebPage();
		break;
		}
		case 3608257228: 
		{
			return new COMMON::UpdateDialogPinned();
		break;
		}
		case 3637180045: 
		{
			return new COMMON::UpdatePinnedDialogs();
		break;
		}
		case 2199371971: 
		{
			return new COMMON::UpdateBotWebhookJSON();
		break;
		}
		case 2610053286: 
		{
			return new COMMON::UpdateBotWebhookJSONQuery();
		break;
		}
		case 3771582784: 
		{
			return new COMMON::UpdateBotShippingQuery();
		break;
		}
		case 1563376297: 
		{
			return new COMMON::UpdateBotPrecheckoutQuery();
		break;
		}
		case 2869914398: 
		{
			return new COMMON::UpdatePhoneCall();
		break;
		}
		case 281165899: 
		{
			return new COMMON::UpdateLangPackTooLong();
		break;
		}
		case 1442983757: 
		{
			return new COMMON::UpdateLangPack();
		break;
		}
		case 3843135853: 
		{
			return new COMMON::UpdateFavedStickers();
		break;
		}
		case 2307472197: 
		{
			return new COMMON::UpdateChannelReadMessagesContents();
		break;
		}
		case 1887741886: 
		{
			return new COMMON::UpdateContactsReset();
		break;
		}
		case 1893427255: 
		{
			return new COMMON::UpdateChannelAvailableMessages();
		break;
		}
		case 2775329342: 
		{
			return new UPDATES::State();
		break;
		}
		case 1567990072: 
		{
			return new UPDATES::DifferenceEmpty();
		break;
		}
		case 16030880: 
		{
			return new UPDATES::Difference();
		break;
		}
		case 2835028353: 
		{
			return new UPDATES::DifferenceSlice();
		break;
		}
		case 1258196845: 
		{
			return new UPDATES::DifferenceTooLong();
		break;
		}
		case 3809980286: 
		{
			return new COMMON::UpdatesTooLong();
		break;
		}
		case 2437922577: 
		{
			return new COMMON::UpdateShortMessage();
		break;
		}
		case 377562760: 
		{
			return new COMMON::UpdateShortChatMessage();
		break;
		}
		case 2027216577: 
		{
			return new COMMON::UpdateShort();
		break;
		}
		case 1918567619: 
		{
			return new COMMON::UpdatesCombined();
		break;
		}
		case 1957577280: 
		{
			return new COMMON::Updates();
		break;
		}
		case 301019932: 
		{
			return new COMMON::UpdateShortSentMessage();
		break;
		}
		case 2378853029: 
		{
			return new PHOTOS::Photos();
		break;
		}
		case 352657236: 
		{
			return new PHOTOS::PhotosSlice();
		break;
		}
		case 539045032: 
		{
			return new PHOTOS::Photo();
		break;
		}
		case 157948117: 
		{
			return new UPLOAD::File();
		break;
		}
		case 3931307610: 
		{
			return new UPLOAD::FileCdnRedirect();
		break;
		}
		case 98092748: 
		{
			return new COMMON::DcOption();
		break;
		}
		case 2625898852: 
		{
			return new COMMON::Config();
		break;
		}
		case 2384074613: 
		{
			return new COMMON::NearestDc();
		break;
		}
		case 2307388177: 
		{
			return new HELP::AppUpdate();
		break;
		}
		case 3294258486: 
		{
			return new HELP::NoAppUpdate();
		break;
		}
		case 415997816: 
		{
			return new HELP::InviteText();
		break;
		}
		case 2877210784: 
		{
			return new COMMON::EncryptedChatEmpty();
		break;
		}
		case 1006044124: 
		{
			return new COMMON::EncryptedChatWaiting();
		break;
		}
		case 3363328638: 
		{
			return new COMMON::EncryptedChatRequested();
		break;
		}
		case 4199992886: 
		{
			return new COMMON::EncryptedChat();
		break;
		}
		case 332848423: 
		{
			return new COMMON::EncryptedChatDiscarded();
		break;
		}
		case 4047615457: 
		{
			return new COMMON::InputEncryptedChat();
		break;
		}
		case 3256830334: 
		{
			return new COMMON::EncryptedFileEmpty();
		break;
		}
		case 1248893260: 
		{
			return new COMMON::EncryptedFile();
		break;
		}
		case 406307684: 
		{
			return new COMMON::InputEncryptedFileEmpty();
		break;
		}
		case 1690108678: 
		{
			return new COMMON::InputEncryptedFileUploaded();
		break;
		}
		case 1511503333: 
		{
			return new COMMON::InputEncryptedFile();
		break;
		}
		case 767652808: 
		{
			return new COMMON::InputEncryptedFileBigUploaded();
		break;
		}
		case 3977822488: 
		{
			return new COMMON::EncryptedMessage();
		break;
		}
		case 594758406: 
		{
			return new COMMON::EncryptedMessageService();
		break;
		}
		case 3236054581: 
		{
			return new MESSAGES::DhConfigNotModified();
		break;
		}
		case 740433629: 
		{
			return new MESSAGES::DhConfig();
		break;
		}
		case 1443858741: 
		{
			return new MESSAGES::SentEncryptedMessage();
		break;
		}
		case 2492727090: 
		{
			return new MESSAGES::SentEncryptedFile();
		break;
		}
		case 1928391342: 
		{
			return new COMMON::InputDocumentEmpty();
		break;
		}
		case 410618194: 
		{
			return new COMMON::InputDocument();
		break;
		}
		case 922273905: 
		{
			return new COMMON::DocumentEmpty();
		break;
		}
		case 2267229127: 
		{
			return new COMMON::Document();
		break;
		}
		case 398898678: 
		{
			return new HELP::Support();
		break;
		}
		case 2681474008: 
		{
			return new COMMON::NotifyPeer();
		break;
		}
		case 3033021260: 
		{
			return new COMMON::NotifyUsers();
		break;
		}
		case 3221737155: 
		{
			return new COMMON::NotifyChats();
		break;
		}
		case 1959820384: 
		{
			return new COMMON::NotifyAll();
		break;
		}
		case 381645902: 
		{
			return new COMMON::SendMessageTypingAction();
		break;
		}
		case 4250847477: 
		{
			return new COMMON::SendMessageCancelAction();
		break;
		}
		case 2710034031: 
		{
			return new COMMON::SendMessageRecordVideoAction();
		break;
		}
		case 3916839660: 
		{
			return new COMMON::SendMessageUploadVideoAction();
		break;
		}
		case 3576656887: 
		{
			return new COMMON::SendMessageRecordAudioAction();
		break;
		}
		case 4082227115: 
		{
			return new COMMON::SendMessageUploadAudioAction();
		break;
		}
		case 3520285222: 
		{
			return new COMMON::SendMessageUploadPhotoAction();
		break;
		}
		case 2852968932: 
		{
			return new COMMON::SendMessageUploadDocumentAction();
		break;
		}
		case 393186209: 
		{
			return new COMMON::SendMessageGeoLocationAction();
		break;
		}
		case 1653390447: 
		{
			return new COMMON::SendMessageChooseContactAction();
		break;
		}
		case 3714748232: 
		{
			return new COMMON::SendMessageGamePlayAction();
		break;
		}
		case 2297593788: 
		{
			return new COMMON::SendMessageRecordRoundAction();
		break;
		}
		case 608050278: 
		{
			return new COMMON::SendMessageUploadRoundAction();
		break;
		}
		case 446822276: 
		{
			return new CONTACTS::Found();
		break;
		}
		case 1335282456: 
		{
			return new COMMON::InputPrivacyKeyStatusTimestamp();
		break;
		}
		case 3187344422: 
		{
			return new COMMON::InputPrivacyKeyChatInvite();
		break;
		}
		case 4206550111: 
		{
			return new COMMON::InputPrivacyKeyPhoneCall();
		break;
		}
		case 3157175088: 
		{
			return new COMMON::PrivacyKeyStatusTimestamp();
		break;
		}
		case 1343122938: 
		{
			return new COMMON::PrivacyKeyChatInvite();
		break;
		}
		case 1030105979: 
		{
			return new COMMON::PrivacyKeyPhoneCall();
		break;
		}
		case 218751099: 
		{
			return new COMMON::InputPrivacyValueAllowContacts();
		break;
		}
		case 407582158: 
		{
			return new COMMON::InputPrivacyValueAllowAll();
		break;
		}
		case 320652927: 
		{
			return new COMMON::InputPrivacyValueAllowUsers();
		break;
		}
		case 195371015: 
		{
			return new COMMON::InputPrivacyValueDisallowContacts();
		break;
		}
		case 3597362889: 
		{
			return new COMMON::InputPrivacyValueDisallowAll();
		break;
		}
		case 2417034343: 
		{
			return new COMMON::InputPrivacyValueDisallowUsers();
		break;
		}
		case 4294843308: 
		{
			return new COMMON::PrivacyValueAllowContacts();
		break;
		}
		case 1698855810: 
		{
			return new COMMON::PrivacyValueAllowAll();
		break;
		}
		case 1297858060: 
		{
			return new COMMON::PrivacyValueAllowUsers();
		break;
		}
		case 4169726490: 
		{
			return new COMMON::PrivacyValueDisallowContacts();
		break;
		}
		case 2339628899: 
		{
			return new COMMON::PrivacyValueDisallowAll();
		break;
		}
		case 209668535: 
		{
			return new COMMON::PrivacyValueDisallowUsers();
		break;
		}
		case 1430961007: 
		{
			return new ACCOUNT::PrivacyRules();
		break;
		}
		case 3100684255: 
		{
			return new COMMON::AccountDaysTTL();
		break;
		}
		case 1815593308: 
		{
			return new COMMON::DocumentAttributeImageSize();
		break;
		}
		case 297109817: 
		{
			return new COMMON::DocumentAttributeAnimated();
		break;
		}
		case 1662637586: 
		{
			return new COMMON::DocumentAttributeSticker();
		break;
		}
		case 250621158: 
		{
			return new COMMON::DocumentAttributeVideo();
		break;
		}
		case 2555574726: 
		{
			return new COMMON::DocumentAttributeAudio();
		break;
		}
		case 358154344: 
		{
			return new COMMON::DocumentAttributeFilename();
		break;
		}
		case 2550256375: 
		{
			return new COMMON::DocumentAttributeHasStickers();
		break;
		}
		case 4050950690: 
		{
			return new MESSAGES::StickersNotModified();
		break;
		}
		case 2324614450: 
		{
			return new MESSAGES::Stickers();
		break;
		}
		case 313694676: 
		{
			return new COMMON::StickerPack();
		break;
		}
		case 3898999491: 
		{
			return new MESSAGES::AllStickersNotModified();
		break;
		}
		case 3992797279: 
		{
			return new MESSAGES::AllStickers();
		break;
		}
		case 2925752100: 
		{
			return new COMMON::DisabledFeature();
		break;
		}
		case 2228326789: 
		{
			return new MESSAGES::AffectedMessages();
		break;
		}
		case 1599050311: 
		{
			return new COMMON::ContactLinkUnknown();
		break;
		}
		case 4276999085: 
		{
			return new COMMON::ContactLinkNone();
		break;
		}
		case 646922073: 
		{
			return new COMMON::ContactLinkHasPhone();
		break;
		}
		case 3573727952: 
		{
			return new COMMON::ContactLinkContact();
		break;
		}
		case 3943987176: 
		{
			return new COMMON::WebPageEmpty();
		break;
		}
		case 3313949212: 
		{
			return new COMMON::WebPagePending();
		break;
		}
		case 1594340540: 
		{
			return new COMMON::WebPage();
		break;
		}
		case 2240058483: 
		{
			return new COMMON::WebPageNotModified();
		break;
		}
		case 2079516406: 
		{
			return new COMMON::Authorization();
		break;
		}
		case 307276766: 
		{
			return new ACCOUNT::Authorizations();
		break;
		}
		case 2530917400: 
		{
			return new ACCOUNT::NoPassword();
		break;
		}
		case 2081952796: 
		{
			return new ACCOUNT::Password();
		break;
		}
		case 3082234547: 
		{
			return new ACCOUNT::PasswordSettings();
		break;
		}
		case 2257677803: 
		{
			return new ACCOUNT::PasswordInputSettings();
		break;
		}
		case 326715557: 
		{
			return new AUTH::PasswordRecovery();
		break;
		}
		case 2743383929: 
		{
			return new COMMON::ReceivedNotifyMessage();
		break;
		}
		case 1776236393: 
		{
			return new COMMON::ChatInviteEmpty();
		break;
		}
		case 4230874556: 
		{
			return new COMMON::ChatInviteExported();
		break;
		}
		case 1516793212: 
		{
			return new COMMON::ChatInviteAlready();
		break;
		}
		case 3681875288: 
		{
			return new COMMON::ChatInvite();
		break;
		}
		case 4290128789: 
		{
			return new COMMON::InputStickerSetEmpty();
		break;
		}
		case 2649203305: 
		{
			return new COMMON::InputStickerSetID();
		break;
		}
		case 2250033312: 
		{
			return new COMMON::InputStickerSetShortName();
		break;
		}
		case 3442490177: 
		{
			return new COMMON::StickerSet();
		break;
		}
		case 3054118054: 
		{
			return new MESSAGES::StickerSet();
		break;
		}
		case 3262826695: 
		{
			return new COMMON::BotCommand();
		break;
		}
		case 2565348666: 
		{
			return new COMMON::BotInfo();
		break;
		}
		case 2734311552: 
		{
			return new COMMON::KeyboardButton();
		break;
		}
		case 629866245: 
		{
			return new COMMON::KeyboardButtonUrl();
		break;
		}
		case 1748655686: 
		{
			return new COMMON::KeyboardButtonCallback();
		break;
		}
		case 2976541737: 
		{
			return new COMMON::KeyboardButtonRequestPhone();
		break;
		}
		case 4235815743: 
		{
			return new COMMON::KeyboardButtonRequestGeoLocation();
		break;
		}
		case 90744648: 
		{
			return new COMMON::KeyboardButtonSwitchInline();
		break;
		}
		case 1358175439: 
		{
			return new COMMON::KeyboardButtonGame();
		break;
		}
		case 2950250427: 
		{
			return new COMMON::KeyboardButtonBuy();
		break;
		}
		case 2002815875: 
		{
			return new COMMON::KeyboardButtonRow();
		break;
		}
		case 2688441221: 
		{
			return new COMMON::ReplyKeyboardHide();
		break;
		}
		case 4094724768: 
		{
			return new COMMON::ReplyKeyboardForceReply();
		break;
		}
		case 889353612: 
		{
			return new COMMON::ReplyKeyboardMarkup();
		break;
		}
		case 1218642516: 
		{
			return new COMMON::ReplyInlineMarkup();
		break;
		}
		case 3146955413: 
		{
			return new COMMON::MessageEntityUnknown();
		break;
		}
		case 4194588573: 
		{
			return new COMMON::MessageEntityMention();
		break;
		}
		case 1868782349: 
		{
			return new COMMON::MessageEntityHashtag();
		break;
		}
		case 1827637959: 
		{
			return new COMMON::MessageEntityBotCommand();
		break;
		}
		case 1859134776: 
		{
			return new COMMON::MessageEntityUrl();
		break;
		}
		case 1692693954: 
		{
			return new COMMON::MessageEntityEmail();
		break;
		}
		case 3177253833: 
		{
			return new COMMON::MessageEntityBold();
		break;
		}
		case 2188348256: 
		{
			return new COMMON::MessageEntityItalic();
		break;
		}
		case 681706865: 
		{
			return new COMMON::MessageEntityCode();
		break;
		}
		case 1938967520: 
		{
			return new COMMON::MessageEntityPre();
		break;
		}
		case 1990644519: 
		{
			return new COMMON::MessageEntityTextUrl();
		break;
		}
		case 892193368: 
		{
			return new COMMON::MessageEntityMentionName();
		break;
		}
		case 546203849: 
		{
			return new COMMON::InputMessageEntityMentionName();
		break;
		}
		case 4002160262: 
		{
			return new COMMON::InputChannelEmpty();
		break;
		}
		case 2951442734: 
		{
			return new COMMON::InputChannel();
		break;
		}
		case 2131196633: 
		{
			return new CONTACTS::ResolvedPeer();
		break;
		}
		case 182649427: 
		{
			return new COMMON::MessageRange();
		break;
		}
		case 1041346555: 
		{
			return new UPDATES::ChannelDifferenceEmpty();
		break;
		}
		case 1788705589: 
		{
			return new UPDATES::ChannelDifferenceTooLong();
		break;
		}
		case 543450958: 
		{
			return new UPDATES::ChannelDifference();
		break;
		}
		case 2496933607: 
		{
			return new COMMON::ChannelMessagesFilterEmpty();
		break;
		}
		case 3447183703: 
		{
			return new COMMON::ChannelMessagesFilter();
		break;
		}
		case 367766557: 
		{
			return new COMMON::ChannelParticipant();
		break;
		}
		case 2737347181: 
		{
			return new COMMON::ChannelParticipantSelf();
		break;
		}
		case 3823297017: 
		{
			return new COMMON::ChannelParticipantCreator();
		break;
		}
		case 2821695640: 
		{
			return new COMMON::ChannelParticipantAdmin();
		break;
		}
		case 573315206: 
		{
			return new COMMON::ChannelParticipantBanned();
		break;
		}
		case 3728686201: 
		{
			return new COMMON::ChannelParticipantsRecent();
		break;
		}
		case 3026225513: 
		{
			return new COMMON::ChannelParticipantsAdmins();
		break;
		}
		case 2746567045: 
		{
			return new COMMON::ChannelParticipantsKicked();
		break;
		}
		case 2966521435: 
		{
			return new COMMON::ChannelParticipantsBots();
		break;
		}
		case 338142689: 
		{
			return new COMMON::ChannelParticipantsBanned();
		break;
		}
		case 106343499: 
		{
			return new COMMON::ChannelParticipantsSearch();
		break;
		}
		case 4117684904: 
		{
			return new CHANNELS::ChannelParticipants();
		break;
		}
		case 4028055529: 
		{
			return new CHANNELS::ChannelParticipantsNotModified();
		break;
		}
		case 3503927651: 
		{
			return new CHANNELS::ChannelParticipant();
		break;
		}
		case 4058922640: 
		{
			return new HELP::TermsOfService();
		break;
		}
		case 372165663: 
		{
			return new COMMON::FoundGif();
		break;
		}
		case 2624914441: 
		{
			return new COMMON::FoundGifCached();
		break;
		}
		case 1158290442: 
		{
			return new MESSAGES::FoundGifs();
		break;
		}
		case 3892468898: 
		{
			return new MESSAGES::SavedGifsNotModified();
		break;
		}
		case 772213157: 
		{
			return new MESSAGES::SavedGifs();
		break;
		}
		case 691006739: 
		{
			return new COMMON::InputBotInlineMessageMediaAuto();
		break;
		}
		case 1036876423: 
		{
			return new COMMON::InputBotInlineMessageText();
		break;
		}
		case 3249626469: 
		{
			return new COMMON::InputBotInlineMessageMediaGeo();
		break;
		}
		case 2863640008: 
		{
			return new COMMON::InputBotInlineMessageMediaVenue();
		break;
		}
		case 766443943: 
		{
			return new COMMON::InputBotInlineMessageMediaContact();
		break;
		}
		case 1262639204: 
		{
			return new COMMON::InputBotInlineMessageGame();
		break;
		}
		case 750510426: 
		{
			return new COMMON::InputBotInlineResult();
		break;
		}
		case 2832753831: 
		{
			return new COMMON::InputBotInlineResultPhoto();
		break;
		}
		case 4294507972: 
		{
			return new COMMON::InputBotInlineResultDocument();
		break;
		}
		case 1336154098: 
		{
			return new COMMON::InputBotInlineResultGame();
		break;
		}
		case 175419739: 
		{
			return new COMMON::BotInlineMessageMediaAuto();
		break;
		}
		case 2357159394: 
		{
			return new COMMON::BotInlineMessageText();
		break;
		}
		case 3072515685: 
		{
			return new COMMON::BotInlineMessageMediaGeo();
		break;
		}
		case 1130767150: 
		{
			return new COMMON::BotInlineMessageMediaVenue();
		break;
		}
		case 904770772: 
		{
			return new COMMON::BotInlineMessageMediaContact();
		break;
		}
		case 2615914169: 
		{
			return new COMMON::BotInlineResult();
		break;
		}
		case 400266251: 
		{
			return new COMMON::BotInlineMediaResult();
		break;
		}
		case 2491197512: 
		{
			return new MESSAGES::BotResults();
		break;
		}
		case 524838915: 
		{
			return new COMMON::ExportedMessageLink();
		break;
		}
		case 4208981164: 
		{
			return new COMMON::MessageFwdHeader();
		break;
		}
		case 1923290508: 
		{
			return new AUTH::CodeTypeSms();
		break;
		}
		case 1948046307: 
		{
			return new AUTH::CodeTypeCall();
		break;
		}
		case 577556219: 
		{
			return new AUTH::CodeTypeFlashCall();
		break;
		}
		case 1035688326: 
		{
			return new AUTH::SentCodeTypeApp();
		break;
		}
		case 3221273506: 
		{
			return new AUTH::SentCodeTypeSms();
		break;
		}
		case 1398007207: 
		{
			return new AUTH::SentCodeTypeCall();
		break;
		}
		case 2869151449: 
		{
			return new AUTH::SentCodeTypeFlashCall();
		break;
		}
		case 911761060: 
		{
			return new MESSAGES::BotCallbackAnswer();
		break;
		}
		case 649453030: 
		{
			return new MESSAGES::MessageEditData();
		break;
		}
		case 2299280777: 
		{
			return new COMMON::InputBotInlineMessageID();
		break;
		}
		case 1008755359: 
		{
			return new COMMON::InlineBotSwitchPM();
		break;
		}
		case 863093588: 
		{
			return new MESSAGES::PeerDialogs();
		break;
		}
		case 3989684315: 
		{
			return new COMMON::TopPeer();
		break;
		}
		case 2875595611: 
		{
			return new COMMON::TopPeerCategoryBotsPM();
		break;
		}
		case 344356834: 
		{
			return new COMMON::TopPeerCategoryBotsInline();
		break;
		}
		case 104314861: 
		{
			return new COMMON::TopPeerCategoryCorrespondents();
		break;
		}
		case 3172442442: 
		{
			return new COMMON::TopPeerCategoryGroups();
		break;
		}
		case 371037736: 
		{
			return new COMMON::TopPeerCategoryChannels();
		break;
		}
		case 511092620: 
		{
			return new COMMON::TopPeerCategoryPhoneCalls();
		break;
		}
		case 4219683473: 
		{
			return new COMMON::TopPeerCategoryPeers();
		break;
		}
		case 3727060725: 
		{
			return new CONTACTS::TopPeersNotModified();
		break;
		}
		case 1891070632: 
		{
			return new CONTACTS::TopPeers();
		break;
		}
		case 3125522117: 
		{
			return new COMMON::DraftMessageEmpty();
		break;
		}
		case 4253970719: 
		{
			return new COMMON::DraftMessage();
		break;
		}
		case 82699215: 
		{
			return new MESSAGES::FeaturedStickersNotModified();
		break;
		}
		case 4171073765: 
		{
			return new MESSAGES::FeaturedStickers();
		break;
		}
		case 186120336: 
		{
			return new MESSAGES::RecentStickersNotModified();
		break;
		}
		case 1558317424: 
		{
			return new MESSAGES::RecentStickers();
		break;
		}
		case 1338747336: 
		{
			return new MESSAGES::ArchivedStickers();
		break;
		}
		case 946083368: 
		{
			return new MESSAGES::StickerSetInstallResultSuccess();
		break;
		}
		case 904138920: 
		{
			return new MESSAGES::StickerSetInstallResultArchive();
		break;
		}
		case 1678812626: 
		{
			return new COMMON::StickerSetCovered();
		break;
		}
		case 872932635: 
		{
			return new COMMON::StickerSetMultiCovered();
		break;
		}
		case 2933316530: 
		{
			return new COMMON::MaskCoords();
		break;
		}
		case 1251549527: 
		{
			return new COMMON::InputStickeredMediaPhoto();
		break;
		}
		case 70813275: 
		{
			return new COMMON::InputStickeredMediaDocument();
		break;
		}
		case 3187238203: 
		{
			return new COMMON::Game();
		break;
		}
		case 53231223: 
		{
			return new COMMON::InputGameID();
		break;
		}
		case 3274827786: 
		{
			return new COMMON::InputGameShortName();
		break;
		}
		case 1493171408: 
		{
			return new COMMON::HighScore();
		break;
		}
		case 2587622809: 
		{
			return new MESSAGES::HighScores();
		break;
		}
		case 3695018575: 
		{
			return new COMMON::TextEmpty();
		break;
		}
		case 1950782688: 
		{
			return new COMMON::TextPlain();
		break;
		}
		case 1730456516: 
		{
			return new COMMON::TextBold();
		break;
		}
		case 3641877916: 
		{
			return new COMMON::TextItalic();
		break;
		}
		case 3240501956: 
		{
			return new COMMON::TextUnderline();
		break;
		}
		case 2616769429: 
		{
			return new COMMON::TextStrike();
		break;
		}
		case 1816074681: 
		{
			return new COMMON::TextFixed();
		break;
		}
		case 1009288385: 
		{
			return new COMMON::TextUrl();
		break;
		}
		case 3730443734: 
		{
			return new COMMON::TextEmail();
		break;
		}
		case 2120376535: 
		{
			return new COMMON::TextConcat();
		break;
		}
		case 324435594: 
		{
			return new COMMON::PageBlockUnsupported();
		break;
		}
		case 1890305021: 
		{
			return new COMMON::PageBlockTitle();
		break;
		}
		case 2415565343: 
		{
			return new COMMON::PageBlockSubtitle();
		break;
		}
		case 3132089824: 
		{
			return new COMMON::PageBlockAuthorDate();
		break;
		}
		case 3218105580: 
		{
			return new COMMON::PageBlockHeader();
		break;
		}
		case 4046173921: 
		{
			return new COMMON::PageBlockSubheader();
		break;
		}
		case 1182402406: 
		{
			return new COMMON::PageBlockParagraph();
		break;
		}
		case 3228621118: 
		{
			return new COMMON::PageBlockPreformatted();
		break;
		}
		case 1216809369: 
		{
			return new COMMON::PageBlockFooter();
		break;
		}
		case 3676352904: 
		{
			return new COMMON::PageBlockDivider();
		break;
		}
		case 3456972720: 
		{
			return new COMMON::PageBlockAnchor();
		break;
		}
		case 978896884: 
		{
			return new COMMON::PageBlockList();
		break;
		}
		case 641563686: 
		{
			return new COMMON::PageBlockBlockquote();
		break;
		}
		case 1329878739: 
		{
			return new COMMON::PageBlockPullquote();
		break;
		}
		case 3922106754: 
		{
			return new COMMON::PageBlockPhoto();
		break;
		}
		case 3654752358: 
		{
			return new COMMON::PageBlockVideo();
		break;
		}
		case 972174080: 
		{
			return new COMMON::PageBlockCover();
		break;
		}
		case 3454140625: 
		{
			return new COMMON::PageBlockEmbed();
		break;
		}
		case 690781161: 
		{
			return new COMMON::PageBlockEmbedPost();
		break;
		}
		case 145955919: 
		{
			return new COMMON::PageBlockCollage();
		break;
		}
		case 319588707: 
		{
			return new COMMON::PageBlockSlideshow();
		break;
		}
		case 4011282869: 
		{
			return new COMMON::PageBlockChannel();
		break;
		}
		case 834148991: 
		{
			return new COMMON::PageBlockAudio();
		break;
		}
		case 2386534078: 
		{
			return new COMMON::PagePart();
		break;
		}
		case 1433323434: 
		{
			return new COMMON::PageFull();
		break;
		}
		case 2246320897: 
		{
			return new COMMON::PhoneCallDiscardReasonMissed();
		break;
		}
		case 3767910816: 
		{
			return new COMMON::PhoneCallDiscardReasonDisconnect();
		break;
		}
		case 1471006352: 
		{
			return new COMMON::PhoneCallDiscardReasonHangup();
		break;
		}
		case 4210550985: 
		{
			return new COMMON::PhoneCallDiscardReasonBusy();
		break;
		}
		case 2104790276: 
		{
			return new COMMON::DataJSON();
		break;
		}
		case 3408489464: 
		{
			return new COMMON::LabeledPrice();
		break;
		}
		case 3272254296: 
		{
			return new COMMON::Invoice();
		break;
		}
		case 3926049406: 
		{
			return new COMMON::PaymentCharge();
		break;
		}
		case 512535275: 
		{
			return new COMMON::PostAddress();
		break;
		}
		case 2426158996: 
		{
			return new COMMON::PaymentRequestedInfo();
		break;
		}
		case 3452074527: 
		{
			return new COMMON::PaymentSavedCredentialsCard();
		break;
		}
		case 3323644888: 
		{
			return new COMMON::WebDocument();
		break;
		}
		case 2616017741: 
		{
			return new COMMON::InputWebDocument();
		break;
		}
		case 3258570374: 
		{
			return new COMMON::InputWebFileLocation();
		break;
		}
		case 568808380: 
		{
			return new UPLOAD::WebFile();
		break;
		}
		case 1062645411: 
		{
			return new PAYMENTS::PaymentForm();
		break;
		}
		case 3510966403: 
		{
			return new PAYMENTS::ValidatedRequestedInfo();
		break;
		}
		case 1314881805: 
		{
			return new PAYMENTS::PaymentResult();
		break;
		}
		case 1800845601: 
		{
			return new PAYMENTS::PaymentVerficationNeeded();
		break;
		}
		case 1342771681: 
		{
			return new PAYMENTS::PaymentReceipt();
		break;
		}
		case 4220511292: 
		{
			return new PAYMENTS::SavedInfo();
		break;
		}
		case 3238965967: 
		{
			return new COMMON::InputPaymentCredentialsSaved();
		break;
		}
		case 873977640: 
		{
			return new COMMON::InputPaymentCredentials();
		break;
		}
		case 3680828724: 
		{
			return new ACCOUNT::TmpPassword();
		break;
		}
		case 3055631583: 
		{
			return new COMMON::ShippingOption();
		break;
		}
		case 4288717974: 
		{
			return new COMMON::InputStickerSetItem();
		break;
		}
		case 506920429: 
		{
			return new COMMON::InputPhoneCall();
		break;
		}
		case 1399245077: 
		{
			return new COMMON::PhoneCallEmpty();
		break;
		}
		case 462375633: 
		{
			return new COMMON::PhoneCallWaiting();
		break;
		}
		case 2205555940: 
		{
			return new COMMON::PhoneCallRequested();
		break;
		}
		case 1828732223: 
		{
			return new COMMON::PhoneCallAccepted();
		break;
		}
		case 4293307239: 
		{
			return new COMMON::PhoneCall();
		break;
		}
		case 1355435489: 
		{
			return new COMMON::PhoneCallDiscarded();
		break;
		}
		case 2639009728: 
		{
			return new COMMON::PhoneConnection();
		break;
		}
		case 2730177995: 
		{
			return new COMMON::PhoneCallProtocol();
		break;
		}
		case 3968000320: 
		{
			return new PHONE::PhoneCall();
		break;
		}
		case 4004045934: 
		{
			return new UPLOAD::CdnFileReuploadNeeded();
		break;
		}
		case 2845821519: 
		{
			return new UPLOAD::CdnFile();
		break;
		}
		case 3380800186: 
		{
			return new COMMON::CdnPublicKey();
		break;
		}
		case 1462101002: 
		{
			return new COMMON::CdnConfig();
		break;
		}
		case 3402727926: 
		{
			return new COMMON::LangPackString();
		break;
		}
		case 1816636575: 
		{
			return new COMMON::LangPackStringPluralized();
		break;
		}
		case 695856818: 
		{
			return new COMMON::LangPackStringDeleted();
		break;
		}
		case 4085629430: 
		{
			return new COMMON::LangPackDifference();
		break;
		}
		case 292985073: 
		{
			return new COMMON::LangPackLanguage();
		break;
		}
		case 1568467877: 
		{
			return new COMMON::ChannelAdminRights();
		break;
		}
		case 1489977929: 
		{
			return new COMMON::ChannelBannedRights();
		break;
		}
		case 3873421349: 
		{
			return new COMMON::ChannelAdminLogEventActionChangeTitle();
		break;
		}
		case 1427671598: 
		{
			return new COMMON::ChannelAdminLogEventActionChangeAbout();
		break;
		}
		case 1783299128: 
		{
			return new COMMON::ChannelAdminLogEventActionChangeUsername();
		break;
		}
		case 3090109891: 
		{
			return new COMMON::ChannelAdminLogEventActionChangePhoto();
		break;
		}
		case 460916654: 
		{
			return new COMMON::ChannelAdminLogEventActionToggleInvites();
		break;
		}
		case 648939889: 
		{
			return new COMMON::ChannelAdminLogEventActionToggleSignatures();
		break;
		}
		case 3924306968: 
		{
			return new COMMON::ChannelAdminLogEventActionUpdatePinned();
		break;
		}
		case 1889215493: 
		{
			return new COMMON::ChannelAdminLogEventActionEditMessage();
		break;
		}
		case 1121994683: 
		{
			return new COMMON::ChannelAdminLogEventActionDeleteMessage();
		break;
		}
		case 405815507: 
		{
			return new COMMON::ChannelAdminLogEventActionParticipantJoin();
		break;
		}
		case 4170676210: 
		{
			return new COMMON::ChannelAdminLogEventActionParticipantLeave();
		break;
		}
		case 3810276568: 
		{
			return new COMMON::ChannelAdminLogEventActionParticipantInvite();
		break;
		}
		case 3872931198: 
		{
			return new COMMON::ChannelAdminLogEventActionParticipantToggleBan();
		break;
		}
		case 3580323600: 
		{
			return new COMMON::ChannelAdminLogEventActionParticipantToggleAdmin();
		break;
		}
		case 2982398631: 
		{
			return new COMMON::ChannelAdminLogEventActionChangeStickerSet();
		break;
		}
		case 1599903217: 
		{
			return new COMMON::ChannelAdminLogEventActionTogglePreHistoryHidden();
		break;
		}
		case 995769920: 
		{
			return new COMMON::ChannelAdminLogEvent();
		break;
		}
		case 3985307469: 
		{
			return new CHANNELS::AdminLogResults();
		break;
		}
		case 3926948580: 
		{
			return new COMMON::ChannelAdminLogEventsFilter();
		break;
		}
		case 1558266229: 
		{
			return new COMMON::PopularContact();
		break;
		}
		case 2012136335: 
		{
			return new COMMON::CdnFileHash();
		break;
		}
		case 2660214483: 
		{
			return new MESSAGES::FavedStickersNotModified();
		break;
		}
		case 4085198614: 
		{
			return new MESSAGES::FavedStickers();
		break;
		}
		case 235081943: 
		{
			return new HELP::RecentMeUrls();
		break;
		}
		case 2377921334: 
		{
			return new COMMON::RecentMeUrlUser();
		break;
		}
		case 2686132985: 
		{
			return new COMMON::RecentMeUrlChat();
		break;
		}
		case 3154794460: 
		{
			return new COMMON::RecentMeUrlStickerSet();
		break;
		}
		case 3947431965: 
		{
			return new COMMON::RecentMeUrlChatInvite();
		break;
		}
		case 1189204285: 
		{
			return new COMMON::RecentMeUrlUnknown();
		break;
		}
		case 3416209197: 
		{
			return new COMMON::InvokeAfterMsg();
		break;
		}
		case 1036301552: 
		{
			return new COMMON::InvokeAfterMsgs();
		break;
		}
		case 3343392166: 
		{
			return new COMMON::InitConnection();
		break;
		}
		case 3667594509: 
		{
			return new COMMON::InvokeWithLayer();
		break;
		}
		case 3214170551: 
		{
			return new COMMON::InvokeWithoutUpdates();
		break;
		}
		case 1877286395: 
		{
			return new AUTH::CheckPhone();
		break;
		}
		case 2259611884: 
		{
			return new AUTH::SendCode();
		break;
		}
		case 453408308: 
		{
			return new AUTH::SignUp();
		break;
		}
		case 3168081281: 
		{
			return new AUTH::SignIn();
		break;
		}
		case 1461180992: 
		{
			return new AUTH::LogOut();
		break;
		}
		case 2678787354: 
		{
			return new AUTH::ResetAuthorizations();
		break;
		}
		case 1998331287: 
		{
			return new AUTH::SendInvites();
		break;
		}
		case 3854565325: 
		{
			return new AUTH::ExportAuthorization();
		break;
		}
		case 3824129555: 
		{
			return new AUTH::ImportAuthorization();
		break;
		}
		case 3453233669: 
		{
			return new AUTH::BindTempAuthKey();
		break;
		}
		case 1738800940: 
		{
			return new AUTH::ImportBotAuthorization();
		break;
		}
		case 174260510: 
		{
			return new AUTH::CheckPassword();
		break;
		}
		case 3633822822: 
		{
			return new AUTH::RequestPasswordRecovery();
		break;
		}
		case 1319464594: 
		{
			return new AUTH::RecoverPassword();
		break;
		}
		case 1056025023: 
		{
			return new AUTH::ResendCode();
		break;
		}
		case 520357240: 
		{
			return new AUTH::CancelCode();
		break;
		}
		case 2387124616: 
		{
			return new AUTH::DropTempAuthKeys();
		break;
		}
		case 1669245048: 
		{
			return new ACCOUNT::RegisterDevice();
		break;
		}
		case 1707432768: 
		{
			return new ACCOUNT::UnregisterDevice();
		break;
		}
		case 2227067795: 
		{
			return new ACCOUNT::UpdateNotifySettings();
		break;
		}
		case 313765169: 
		{
			return new ACCOUNT::GetNotifySettings();
		break;
		}
		case 3682473799: 
		{
			return new ACCOUNT::ResetNotifySettings();
		break;
		}
		case 2018596725: 
		{
			return new ACCOUNT::UpdateProfile();
		break;
		}
		case 1713919532: 
		{
			return new ACCOUNT::UpdateStatus();
		break;
		}
		case 3226270402: 
		{
			return new ACCOUNT::GetWallPapers();
		break;
		}
		case 2920848735: 
		{
			return new ACCOUNT::ReportPeer();
		break;
		}
		case 655677548: 
		{
			return new ACCOUNT::CheckUsername();
		break;
		}
		case 1040964988: 
		{
			return new ACCOUNT::UpdateUsername();
		break;
		}
		case 3671837008: 
		{
			return new ACCOUNT::GetPrivacy();
		break;
		}
		case 3388480744: 
		{
			return new ACCOUNT::SetPrivacy();
		break;
		}
		case 1099779595: 
		{
			return new ACCOUNT::DeleteAccount();
		break;
		}
		case 150761757: 
		{
			return new ACCOUNT::GetAccountTTL();
		break;
		}
		case 608323678: 
		{
			return new ACCOUNT::SetAccountTTL();
		break;
		}
		case 149257707: 
		{
			return new ACCOUNT::SendChangePhoneCode();
		break;
		}
		case 1891839707: 
		{
			return new ACCOUNT::ChangePhone();
		break;
		}
		case 954152242: 
		{
			return new ACCOUNT::UpdateDeviceLocked();
		break;
		}
		case 3810574680: 
		{
			return new ACCOUNT::GetAuthorizations();
		break;
		}
		case 3749180348: 
		{
			return new ACCOUNT::ResetAuthorization();
		break;
		}
		case 1418342645: 
		{
			return new ACCOUNT::GetPassword();
		break;
		}
		case 3163361723: 
		{
			return new ACCOUNT::GetPasswordSettings();
		break;
		}
		case 4202449798: 
		{
			return new ACCOUNT::UpdatePasswordSettings();
		break;
		}
		case 353818557: 
		{
			return new ACCOUNT::SendConfirmPhoneCode();
		break;
		}
		case 1596029123: 
		{
			return new ACCOUNT::ConfirmPhone();
		break;
		}
		case 1250046590: 
		{
			return new ACCOUNT::GetTmpPassword();
		break;
		}
		case 227648840: 
		{
			return new USERS::GetUsers();
		break;
		}
		case 3392185777: 
		{
			return new USERS::GetFullUser();
		break;
		}
		case 3299038190: 
		{
			return new CONTACTS::GetStatuses();
		break;
		}
		case 3223553183: 
		{
			return new CONTACTS::GetContacts();
		break;
		}
		case 746589157: 
		{
			return new CONTACTS::ImportContacts();
		break;
		}
		case 2392143684: 
		{
			return new CONTACTS::DeleteContact();
		break;
		}
		case 1504393374: 
		{
			return new CONTACTS::DeleteContacts();
		break;
		}
		case 858475004: 
		{
			return new CONTACTS::Block();
		break;
		}
		case 3846242493: 
		{
			return new CONTACTS::Unblock();
		break;
		}
		case 4118557967: 
		{
			return new CONTACTS::GetBlocked();
		break;
		}
		case 2229614391: 
		{
			return new CONTACTS::ExportCard();
		break;
		}
		case 1340184318: 
		{
			return new CONTACTS::ImportCard();
		break;
		}
		case 301470424: 
		{
			return new CONTACTS::Search();
		break;
		}
		case 4181511075: 
		{
			return new CONTACTS::ResolveUsername();
		break;
		}
		case 3566742965: 
		{
			return new CONTACTS::GetTopPeers();
		break;
		}
		case 451113900: 
		{
			return new CONTACTS::ResetTopPeerRating();
		break;
		}
		case 2274703345: 
		{
			return new CONTACTS::ResetSaved();
		break;
		}
		case 1109588596: 
		{
			return new MESSAGES::GetMessages();
		break;
		}
		case 421243333: 
		{
			return new MESSAGES::GetDialogs();
		break;
		}
		case 2947098694: 
		{
			return new MESSAGES::GetHistory();
		break;
		}
		case 60726944: 
		{
			return new MESSAGES::Search();
		break;
		}
		case 238054714: 
		{
			return new MESSAGES::ReadHistory();
		break;
		}
		case 469850889: 
		{
			return new MESSAGES::DeleteHistory();
		break;
		}
		case 3851326930: 
		{
			return new MESSAGES::DeleteMessages();
		break;
		}
		case 94983360: 
		{
			return new MESSAGES::ReceivedMessages();
		break;
		}
		case 2743230032: 
		{
			return new MESSAGES::SetTyping();
		break;
		}
		case 4203233914: 
		{
			return new MESSAGES::SendMessage();
		break;
		}
		case 3371263889: 
		{
			return new MESSAGES::SendMedia();
		break;
		}
		case 1888354709: 
		{
			return new MESSAGES::ForwardMessages();
		break;
		}
		case 3474297563: 
		{
			return new MESSAGES::ReportSpam();
		break;
		}
		case 2834395291: 
		{
			return new MESSAGES::HideReportSpam();
		break;
		}
		case 913498268: 
		{
			return new MESSAGES::GetPeerSettings();
		break;
		}
		case 1013621127: 
		{
			return new MESSAGES::GetChats();
		break;
		}
		case 998448230: 
		{
			return new MESSAGES::GetFullChat();
		break;
		}
		case 3695519829: 
		{
			return new MESSAGES::EditChatTitle();
		break;
		}
		case 3394009560: 
		{
			return new MESSAGES::EditChatPhoto();
		break;
		}
		case 4188056073: 
		{
			return new MESSAGES::AddChatUser();
		break;
		}
		case 3764461334: 
		{
			return new MESSAGES::DeleteChatUser();
		break;
		}
		case 164303470: 
		{
			return new MESSAGES::CreateChat();
		break;
		}
		case 865483769: 
		{
			return new MESSAGES::ForwardMessage();
		break;
		}
		case 651135312: 
		{
			return new MESSAGES::GetDhConfig();
		break;
		}
		case 4132286275: 
		{
			return new MESSAGES::RequestEncryption();
		break;
		}
		case 1035731989: 
		{
			return new MESSAGES::AcceptEncryption();
		break;
		}
		case 3990430661: 
		{
			return new MESSAGES::DiscardEncryption();
		break;
		}
		case 2031374829: 
		{
			return new MESSAGES::SetEncryptedTyping();
		break;
		}
		case 2135648522: 
		{
			return new MESSAGES::ReadEncryptedHistory();
		break;
		}
		case 2843174771: 
		{
			return new MESSAGES::SendEncrypted();
		break;
		}
		case 2593135462: 
		{
			return new MESSAGES::SendEncryptedFile();
		break;
		}
		case 852769188: 
		{
			return new MESSAGES::SendEncryptedService();
		break;
		}
		case 1436924774: 
		{
			return new MESSAGES::ReceivedQueue();
		break;
		}
		case 1259113487: 
		{
			return new MESSAGES::ReportEncryptedSpam();
		break;
		}
		case 916930423: 
		{
			return new MESSAGES::ReadMessageContents();
		break;
		}
		case 479598769: 
		{
			return new MESSAGES::GetAllStickers();
		break;
		}
		case 623001124: 
		{
			return new MESSAGES::GetWebPagePreview();
		break;
		}
		case 2106086025: 
		{
			return new MESSAGES::ExportChatInvite();
		break;
		}
		case 1051570619: 
		{
			return new MESSAGES::CheckChatInvite();
		break;
		}
		case 1817183516: 
		{
			return new MESSAGES::ImportChatInvite();
		break;
		}
		case 639215886: 
		{
			return new MESSAGES::GetStickerSet();
		break;
		}
		case 3348096096: 
		{
			return new MESSAGES::InstallStickerSet();
		break;
		}
		case 4184757726: 
		{
			return new MESSAGES::UninstallStickerSet();
		break;
		}
		case 3873403768: 
		{
			return new MESSAGES::StartBot();
		break;
		}
		case 3301483869: 
		{
			return new MESSAGES::GetMessagesViews();
		break;
		}
		case 3968588257: 
		{
			return new MESSAGES::ToggleChatAdmins();
		break;
		}
		case 2850463534: 
		{
			return new MESSAGES::EditChatAdmin();
		break;
		}
		case 363051235: 
		{
			return new MESSAGES::MigrateChat();
		break;
		}
		case 2654776496: 
		{
			return new MESSAGES::SearchGlobal();
		break;
		}
		case 2016638777: 
		{
			return new MESSAGES::ReorderStickerSets();
		break;
		}
		case 864953444: 
		{
			return new MESSAGES::GetDocumentByHash();
		break;
		}
		case 3214571371: 
		{
			return new MESSAGES::SearchGifs();
		break;
		}
		case 2210348370: 
		{
			return new MESSAGES::GetSavedGifs();
		break;
		}
		case 846868683: 
		{
			return new MESSAGES::SaveGif();
		break;
		}
		case 1364105629: 
		{
			return new MESSAGES::GetInlineBotResults();
		break;
		}
		case 3948847622: 
		{
			return new MESSAGES::SetInlineBotResults();
		break;
		}
		case 2976777982: 
		{
			return new MESSAGES::SendInlineBotResult();
		break;
		}
		case 4255550774: 
		{
			return new MESSAGES::GetMessageEditData();
		break;
		}
		case 97630429: 
		{
			return new MESSAGES::EditMessage();
		break;
		}
		case 319564933: 
		{
			return new MESSAGES::EditInlineBotMessage();
		break;
		}
		case 2164957164: 
		{
			return new MESSAGES::GetBotCallbackAnswer();
		break;
		}
		case 3582923530: 
		{
			return new MESSAGES::SetBotCallbackAnswer();
		break;
		}
		case 764901049: 
		{
			return new MESSAGES::GetPeerDialogs();
		break;
		}
		case 3157909835: 
		{
			return new MESSAGES::SaveDraft();
		break;
		}
		case 1782549861: 
		{
			return new MESSAGES::GetAllDrafts();
		break;
		}
		case 766298703: 
		{
			return new MESSAGES::GetFeaturedStickers();
		break;
		}
		case 1527873830: 
		{
			return new MESSAGES::ReadFeaturedStickers();
		break;
		}
		case 1587647177: 
		{
			return new MESSAGES::GetRecentStickers();
		break;
		}
		case 958863608: 
		{
			return new MESSAGES::SaveRecentSticker();
		break;
		}
		case 2308530221: 
		{
			return new MESSAGES::ClearRecentStickers();
		break;
		}
		case 1475442322: 
		{
			return new MESSAGES::GetArchivedStickers();
		break;
		}
		case 1706608543: 
		{
			return new MESSAGES::GetMaskStickers();
		break;
		}
		case 3428542412: 
		{
			return new MESSAGES::GetAttachedStickers();
		break;
		}
		case 2398678208: 
		{
			return new MESSAGES::SetGameScore();
		break;
		}
		case 363700068: 
		{
			return new MESSAGES::SetInlineGameScore();
		break;
		}
		case 3894568093: 
		{
			return new MESSAGES::GetGameHighScores();
		break;
		}
		case 258170395: 
		{
			return new MESSAGES::GetInlineGameHighScores();
		break;
		}
		case 218777796: 
		{
			return new MESSAGES::GetCommonChats();
		break;
		}
		case 3953659888: 
		{
			return new MESSAGES::GetAllChats();
		break;
		}
		case 852135825: 
		{
			return new MESSAGES::GetWebPage();
		break;
		}
		case 847887978: 
		{
			return new MESSAGES::ToggleDialogPin();
		break;
		}
		case 2510288452: 
		{
			return new MESSAGES::ReorderPinnedDialogs();
		break;
		}
		case 3797210702: 
		{
			return new MESSAGES::GetPinnedDialogs();
		break;
		}
		case 3858133754: 
		{
			return new MESSAGES::SetBotShippingResults();
		break;
		}
		case 163765653: 
		{
			return new MESSAGES::SetBotPrecheckoutResults();
		break;
		}
		case 1369162417: 
		{
			return new MESSAGES::UploadMedia();
		break;
		}
		case 3380473888: 
		{
			return new MESSAGES::SendScreenshotNotification();
		break;
		}
		case 567151374: 
		{
			return new MESSAGES::GetFavedStickers();
		break;
		}
		case 3120547163: 
		{
			return new MESSAGES::FaveSticker();
		break;
		}
		case 1180140658: 
		{
			return new MESSAGES::GetUnreadMentions();
		break;
		}
		case 613691874: 
		{
			return new MESSAGES::GetRecentLocations();
		break;
		}
		case 251759059: 
		{
			return new MESSAGES::ReadMentions();
		break;
		}
		case 3990128682: 
		{
			return new UPDATES::GetState();
		break;
		}
		case 630429265: 
		{
			return new UPDATES::GetDifference();
		break;
		}
		case 51854712: 
		{
			return new UPDATES::GetChannelDifference();
		break;
		}
		case 4038807890: 
		{
			return new PHOTOS::UpdateProfilePhoto();
		break;
		}
		case 1328726168: 
		{
			return new PHOTOS::UploadProfilePhoto();
		break;
		}
		case 2278522671: 
		{
			return new PHOTOS::DeletePhotos();
		break;
		}
		case 2446144168: 
		{
			return new PHOTOS::GetUserPhotos();
		break;
		}
		case 3003426337: 
		{
			return new UPLOAD::SaveFilePart();
		break;
		}
		case 3819360181: 
		{
			return new UPLOAD::GetFile();
		break;
		}
		case 3732629309: 
		{
			return new UPLOAD::SaveBigFilePart();
		break;
		}
		case 619086221: 
		{
			return new UPLOAD::GetWebFile();
		break;
		}
		case 536919235: 
		{
			return new UPLOAD::GetCdnFile();
		break;
		}
		case 452533257: 
		{
			return new UPLOAD::ReuploadCdnFile();
		break;
		}
		case 4145399931: 
		{
			return new UPLOAD::GetCdnFileHashes();
		break;
		}
		case 3304659051: 
		{
			return new HELP::GetConfig();
		break;
		}
		case 531836966: 
		{
			return new HELP::GetNearestDc();
		break;
		}
		case 2922242454: 
		{
			return new HELP::GetAppUpdate();
		break;
		}
		case 1862465352: 
		{
			return new HELP::SaveAppLog();
		break;
		}
		case 1295590211: 
		{
			return new HELP::GetInviteText();
		break;
		}
		case 2631862477: 
		{
			return new HELP::GetSupport();
		break;
		}
		case 2417028975: 
		{
			return new HELP::GetAppChangelog();
		break;
		}
		case 889286899: 
		{
			return new HELP::GetTermsOfService();
		break;
		}
		case 3961704397: 
		{
			return new HELP::SetBotUpdatesStatus();
		break;
		}
		case 1375900482: 
		{
			return new HELP::GetCdnConfig();
		break;
		}
		case 1036054804: 
		{
			return new HELP::GetRecentMeUrls();
		break;
		}
		case 3423619383: 
		{
			return new CHANNELS::ReadHistory();
		break;
		}
		case 2227305806: 
		{
			return new CHANNELS::DeleteMessages();
		break;
		}
		case 3507345179: 
		{
			return new CHANNELS::DeleteUserHistory();
		break;
		}
		case 4261967888: 
		{
			return new CHANNELS::ReportSpam();
		break;
		}
		case 2480386887: 
		{
			return new CHANNELS::GetMessages();
		break;
		}
		case 306054633: 
		{
			return new CHANNELS::GetParticipants();
		break;
		}
		case 1416484774: 
		{
			return new CHANNELS::GetParticipant();
		break;
		}
		case 176122811: 
		{
			return new CHANNELS::GetChannels();
		break;
		}
		case 141781513: 
		{
			return new CHANNELS::GetFullChannel();
		break;
		}
		case 4102634879: 
		{
			return new CHANNELS::CreateChannel();
		break;
		}
		case 333610782: 
		{
			return new CHANNELS::EditAbout();
		break;
		}
		case 548962836: 
		{
			return new CHANNELS::EditAdmin();
		break;
		}
		case 1450044624: 
		{
			return new CHANNELS::EditTitle();
		break;
		}
		case 4046346185: 
		{
			return new CHANNELS::EditPhoto();
		break;
		}
		case 283557164: 
		{
			return new CHANNELS::CheckUsername();
		break;
		}
		case 890549214: 
		{
			return new CHANNELS::UpdateUsername();
		break;
		}
		case 615851205: 
		{
			return new CHANNELS::JoinChannel();
		break;
		}
		case 4164332181: 
		{
			return new CHANNELS::LeaveChannel();
		break;
		}
		case 429865580: 
		{
			return new CHANNELS::InviteToChannel();
		break;
		}
		case 3344304261: 
		{
			return new CHANNELS::ExportInvite();
		break;
		}
		case 3222347747: 
		{
			return new CHANNELS::DeleteChannel();
		break;
		}
		case 1231065863: 
		{
			return new CHANNELS::ToggleInvites();
		break;
		}
		case 3360084525: 
		{
			return new CHANNELS::ExportMessageLink();
		break;
		}
		case 527021574: 
		{
			return new CHANNELS::ToggleSignatures();
		break;
		}
		case 2804804946: 
		{
			return new CHANNELS::UpdatePinnedMessage();
		break;
		}
		case 2374861527: 
		{
			return new CHANNELS::GetAdminedPublicChannels();
		break;
		}
		case 3218675149: 
		{
			return new CHANNELS::EditBanned();
		break;
		}
		case 870184064: 
		{
			return new CHANNELS::GetAdminLog();
		break;
		}
		case 3935085817: 
		{
			return new CHANNELS::SetStickers();
		break;
		}
		case 3937786936: 
		{
			return new CHANNELS::ReadMessageContents();
		break;
		}
		case 2939592002: 
		{
			return new CHANNELS::DeleteHistory();
		break;
		}
		case 3938171212: 
		{
			return new CHANNELS::TogglePreHistoryHidden();
		break;
		}
		case 2854709741: 
		{
			return new BOTS::SendCustomRequest();
		break;
		}
		case 3860938573: 
		{
			return new BOTS::AnswerWebhookJSONQuery();
		break;
		}
		case 2582681413: 
		{
			return new PAYMENTS::GetPaymentForm();
		break;
		}
		case 2693966208: 
		{
			return new PAYMENTS::GetPaymentReceipt();
		break;
		}
		case 1997180532: 
		{
			return new PAYMENTS::ValidateRequestedInfo();
		break;
		}
		case 730364339: 
		{
			return new PAYMENTS::SendPaymentForm();
		break;
		}
		case 578650699: 
		{
			return new PAYMENTS::GetSavedInfo();
		break;
		}
		case 3627905217: 
		{
			return new PAYMENTS::ClearSavedInfo();
		break;
		}
		case 2614652522: 
		{
			return new STICKERS::CreateStickerSet();
		break;
		}
		case 4151709521: 
		{
			return new STICKERS::RemoveStickerFromSet();
		break;
		}
		case 4290172106: 
		{
			return new STICKERS::ChangeStickerPosition();
		break;
		}
		case 2253651646: 
		{
			return new STICKERS::AddStickerToSet();
		break;
		}
		case 1430593449: 
		{
			return new PHONE::GetCallConfig();
		break;
		}
		case 1536537556: 
		{
			return new PHONE::RequestCall();
		break;
		}
		case 1003664544: 
		{
			return new PHONE::AcceptCall();
		break;
		}
		case 788404002: 
		{
			return new PHONE::ConfirmCall();
		break;
		}
		case 399855457: 
		{
			return new PHONE::ReceivedCall();
		break;
		}
		case 2027164582: 
		{
			return new PHONE::DiscardCall();
		break;
		}
		case 475228724: 
		{
			return new PHONE::SetCallRating();
		break;
		}
		case 662363518: 
		{
			return new PHONE::SaveCallDebug();
		break;
		}
		case 2595603854: 
		{
			return new LANGPACK::GetLangPack();
		break;
		}
		case 773776152: 
		{
			return new LANGPACK::GetStrings();
		break;
		}
		case 187583869: 
		{
			return new LANGPACK::GetDifference();
		break;
		}
		case 2148521341: 
		{
			return new LANGPACK::GetLanguages();
		break;
		}
		default: 
			return nullptr; 
	}
}
int32 CurrentLayer()
{
	return 72;
}
