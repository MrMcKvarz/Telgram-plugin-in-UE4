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
#include "Types/COMMON/Public/ChannelAdminLogEvent.h"
#include "Types/CHANNELS/Public/AdminLogResults.h"
#include "Types/COMMON/Public/ChannelAdminLogEventsFilter.h"
#include "Types/COMMON/Public/PopularContact.h"
#include "Types/COMMON/Public/CdnFileHash.h"
#include "Types/MESSAGES/Public/FavedStickersNotModified.h"
#include "Types/MESSAGES/Public/FavedStickers.h"
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


	TMap<int32, TLBaseObject*> AllObjects;
	AllObjects.Add(1663309317, new COMMON::ResPQ());
	AllObjects.Add(-329594493, new COMMON::PQInnerData());
	AllObjects.Add(1560595321, new COMMON::ServerDHParamsFail());
	AllObjects.Add(1544022224, new COMMON::ServerDHParamsOk());
	AllObjects.Add(-1173517899, new COMMON::ServerDHInnerData());
	AllObjects.Add(1421230950, new COMMON::ClientDHInnerData());
	AllObjects.Add(888654651, new COMMON::DhGenOk());
	AllObjects.Add(-1189094330, new COMMON::DhGenRetry());
	AllObjects.Add(44998054, new COMMON::DhGenFail());
	AllObjects.Add(-723427082, new COMMON::DestroyAuthKeyOk());
	AllObjects.Add(1495441162, new COMMON::DestroyAuthKeyNone());
	AllObjects.Add(328929514, new COMMON::DestroyAuthKeyFail());
	AllObjects.Add(2023179872, new COMMON::ReqPq());
	AllObjects.Add(-1092349225, new COMMON::ReqDHParams());
	AllObjects.Add(526320885, new COMMON::SetClientDHParams());
	AllObjects.Add(1615938513, new COMMON::DestroyAuthKey());
	AllObjects.Add(1505023586, new COMMON::MsgsAck());
	AllObjects.Add(301526951, new COMMON::BadMsgNotification());
	AllObjects.Add(2068098029, new COMMON::BadServerSalt());
	AllObjects.Add(1392208346, new COMMON::MsgsStateReq());
	AllObjects.Add(2109070852, new COMMON::MsgsStateInfo());
	AllObjects.Add(835829900, new COMMON::MsgsAllInfo());
	AllObjects.Add(-968987353, new COMMON::MsgDetailedInfo());
	AllObjects.Add(-541680256, new COMMON::MsgNewDetailedInfo());
	AllObjects.Add(135956093, new COMMON::MsgResendReq());
	AllObjects.Add(432686113, new COMMON::RpcError());
	AllObjects.Add(1859332702, new COMMON::RpcAnswerUnknown());
	AllObjects.Add(-2031781683, new COMMON::RpcAnswerDroppedRunning());
	AllObjects.Add(-1210565980, new COMMON::RpcAnswerDropped());
	AllObjects.Add(-589739767, new COMMON::FutureSalt());
	AllObjects.Add(-1794617170, new COMMON::FutureSalts());
	AllObjects.Add(-982288588, new COMMON::Pong());
	AllObjects.Add(-62578462, new COMMON::DestroySessionOk());
	AllObjects.Add(-917449886, new COMMON::DestroySessionNone());
	AllObjects.Add(134857374, new COMMON::NewSessionCreated());
	AllObjects.Add(-1623877230, new COMMON::HttpWait());
	AllObjects.Add(1940730836, new COMMON::IpPort());
	AllObjects.Add(-977037351, new HELP::ConfigSimple());
	AllObjects.Add(1084744792, new COMMON::RpcDropAnswer());
	AllObjects.Add(79503801, new COMMON::GetFutureSalts());
	AllObjects.Add(-327696774, new COMMON::Ping());
	AllObjects.Add(-1938078989, new COMMON::PingDelayDisconnect());
	AllObjects.Add(639717863, new COMMON::DestroySession());
	AllObjects.Add(-1787928678, new CONTEST::SaveDeveloperInfo());
	AllObjects.Add(932673980, new COMMON::BoolFalse());
	AllObjects.Add(-1250594151, new COMMON::BoolTrue());
	AllObjects.Add(970190143, new COMMON::True());
	AllObjects.Add(-1141261884, new COMMON::Error());
	AllObjects.Add(-871664810, new COMMON::Null());
	AllObjects.Add(-367510657, new COMMON::InputPeerEmpty());
	AllObjects.Add(-914448259, new COMMON::InputPeerSelf());
	AllObjects.Add(1676188439, new COMMON::InputPeerChat());
	AllObjects.Add(-427979141, new COMMON::InputPeerUser());
	AllObjects.Add(-122770144, new COMMON::InputPeerChannel());
	AllObjects.Add(-813266759, new COMMON::InputUserEmpty());
	AllObjects.Add(1068614135, new COMMON::InputUserSelf());
	AllObjects.Add(371730904, new COMMON::InputUser());
	AllObjects.Add(-189295885, new COMMON::InputPhoneContact());
	AllObjects.Add(2146578421, new COMMON::InputFile());
	AllObjects.Add(-1257549830, new COMMON::InputFileBig());
	AllObjects.Add(2146788502, new COMMON::InputMediaEmpty());
	AllObjects.Add(836908847, new COMMON::InputMediaUploadedPhoto());
	AllObjects.Add(976747137, new COMMON::InputMediaPhoto());
	AllObjects.Add(1145160953, new COMMON::InputMediaGeoPoint());
	AllObjects.Add(-2024151898, new COMMON::InputMediaContact());
	AllObjects.Add(-48130333, new COMMON::InputMediaUploadedDocument());
	AllObjects.Add(-1905865894, new COMMON::InputMediaDocument());
	AllObjects.Add(447227688, new COMMON::InputMediaVenue());
	AllObjects.Add(-38780088, new COMMON::InputMediaGifExternal());
	AllObjects.Add(64, new COMMON::InputMediaPhotoExternal());
	AllObjects.Add(893646774, new COMMON::InputMediaDocumentExternal());
	AllObjects.Add(-213696557, new COMMON::InputMediaGame());
	AllObjects.Add(-2060053102, new COMMON::InputMediaInvoice());
	AllObjects.Add(1469031452, new COMMON::InputChatPhotoEmpty());
	AllObjects.Add(-1269465966, new COMMON::InputChatUploadedPhoto());
	AllObjects.Add(934105993, new COMMON::InputChatPhoto());
	AllObjects.Add(-702299676, new COMMON::InputGeoPointEmpty());
	AllObjects.Add(-911427597, new COMMON::InputGeoPoint());
	AllObjects.Add(230676252, new COMMON::InputPhotoEmpty());
	AllObjects.Add(-993618437, new COMMON::InputPhoto());
	AllObjects.Add(-1770953964, new COMMON::InputFileLocation());
	AllObjects.Add(1432167413, new COMMON::InputEncryptedFileLocation());
	AllObjects.Add(604442435, new COMMON::InputDocumentFileLocation());
	AllObjects.Add(-1470757257, new COMMON::InputAppEvent());
	AllObjects.Add(1841082781, new COMMON::PeerUser());
	AllObjects.Add(-1142566726, new COMMON::PeerChat());
	AllObjects.Add(853925309, new COMMON::PeerChannel());
	AllObjects.Add(87791274, new STORAGE::FileUnknown());
	AllObjects.Add(1383054400, new STORAGE::FilePartial());
	AllObjects.Add(982654, new STORAGE::FileJpeg());
	AllObjects.Add(-542449206, new STORAGE::FileGif());
	AllObjects.Add(64, new STORAGE::FilePng());
	AllObjects.Add(-1924129106, new STORAGE::FilePdf());
	AllObjects.Add(1996917330, new STORAGE::FileMp3());
	AllObjects.Add(-1125447349, new STORAGE::FileMov());
	AllObjects.Add(-459223373, new STORAGE::FileMp4());
	AllObjects.Add(1279688976, new STORAGE::FileWebp());
	AllObjects.Add(1181440380, new COMMON::FileLocationUnavailable());
	AllObjects.Add(1989203539, new COMMON::FileLocation());
	AllObjects.Add(-1169161696, new COMMON::UserEmpty());
	AllObjects.Add(-1007414482, new COMMON::User());
	AllObjects.Add(-507899569, new COMMON::UserProfilePhotoEmpty());
	AllObjects.Add(-925345323, new COMMON::UserProfilePhoto());
	AllObjects.Add(64, new COMMON::UserStatusEmpty());
	AllObjects.Add(1228519917, new COMMON::UserStatusOnline());
	AllObjects.Add(4157580, new COMMON::UserStatusOffline());
	AllObjects.Add(-247304222, new COMMON::UserStatusRecently());
	AllObjects.Add(64, new COMMON::UserStatusLastWeek());
	AllObjects.Add(1120398199, new COMMON::UserStatusLastMonth());
	AllObjects.Add(14197403, new COMMON::ChatEmpty());
	AllObjects.Add(1423776985, new COMMON::Chat());
	AllObjects.Add(64, new COMMON::ChatForbidden());
	AllObjects.Add(64, new COMMON::Channel());
	AllObjects.Add(849845544, new COMMON::ChannelForbidden());
	AllObjects.Add(346423854, new COMMON::ChatFull());
	AllObjects.Add(-815795177, new COMMON::ChannelFull());
	AllObjects.Add(1045026760, new COMMON::ChatParticipant());
	AllObjects.Add(-1974266918, new COMMON::ChatParticipantCreator());
	AllObjects.Add(920966882, new COMMON::ChatParticipantAdmin());
	AllObjects.Add(722243836, new COMMON::ChatParticipantsForbidden());
	AllObjects.Add(-317766081, new COMMON::ChatParticipants());
	AllObjects.Add(469877047, new COMMON::ChatPhotoEmpty());
	AllObjects.Add(1780962145, new COMMON::ChatPhoto());
	AllObjects.Add(1423893891, new COMMON::MessageEmpty());
	AllObjects.Add(299687312, new COMMON::Message());
	AllObjects.Add(-157214306, new COMMON::MessageService());
	AllObjects.Add(543419709, new COMMON::MessageMediaEmpty());
	AllObjects.Add(255533749, new COMMON::MessageMediaPhoto());
	AllObjects.Add(1960108118, new COMMON::MessageMediaGeo());
	AllObjects.Add(959413598, new COMMON::MessageMediaContact());
	AllObjects.Add(-1628142433, new COMMON::MessageMediaUnsupported());
	AllObjects.Add(-753646468, new COMMON::MessageMediaDocument());
	AllObjects.Add(14036387, new COMMON::MessageMediaWebPage());
	AllObjects.Add(532091513, new COMMON::MessageMediaVenue());
	AllObjects.Add(143700477, new COMMON::MessageMediaGame());
	AllObjects.Add(1192449412, new COMMON::MessageMediaInvoice());
	AllObjects.Add(-1325945162, new COMMON::MessageActionEmpty());
	AllObjects.Add(-1702141018, new COMMON::MessageActionChatCreate());
	AllObjects.Add(1523491253, new COMMON::MessageActionChatEditTitle());
	AllObjects.Add(-1475097729, new COMMON::MessageActionChatEditPhoto());
	AllObjects.Add(-268704875, new COMMON::MessageActionChatDeletePhoto());
	AllObjects.Add(930318920, new COMMON::MessageActionChatAddUser());
	AllObjects.Add(211529394, new COMMON::MessageActionChatDeleteUser());
	AllObjects.Add(-386556680, new COMMON::MessageActionChatJoinedByLink());
	AllObjects.Add(-1834167659, new COMMON::MessageActionChannelCreate());
	AllObjects.Add(565230929, new COMMON::MessageActionChatMigrateTo());
	AllObjects.Add(-286632528, new COMMON::MessageActionChannelMigrateFrom());
	AllObjects.Add(-315048556, new COMMON::MessageActionPinMessage());
	AllObjects.Add(79084191, new COMMON::MessageActionHistoryClear());
	AllObjects.Add(1982375826, new COMMON::MessageActionGameScore());
	AllObjects.Add(666055055, new COMMON::MessageActionPaymentSentMe());
	AllObjects.Add(-795055808, new COMMON::MessageActionPaymentSent());
	AllObjects.Add(2132468096, new COMMON::MessageActionPhoneCall());
	AllObjects.Add(-1684893113, new COMMON::MessageActionScreenshotTaken());
	AllObjects.Add(-604643612, new COMMON::Dialog());
	AllObjects.Add(766652707, new COMMON::PhotoEmpty());
	AllObjects.Add(702384274, new COMMON::Photo());
	AllObjects.Add(64, new COMMON::PhotoSizeEmpty());
	AllObjects.Add(464961399, new COMMON::PhotoSize());
	AllObjects.Add(-97212439, new COMMON::PhotoCachedSize());
	AllObjects.Add(1608324881, new COMMON::GeoPointEmpty());
	AllObjects.Add(215435552, new COMMON::GeoPoint());
	AllObjects.Add(-1901977983, new AUTH::CheckedPhone());
	AllObjects.Add(35979358, new AUTH::SentCode());
	AllObjects.Add(369690061, new AUTH::Authorization());
	AllObjects.Add(765236959, new AUTH::ExportedAuthorization());
	AllObjects.Add(207338680, new COMMON::InputNotifyPeer());
	AllObjects.Add(390347545, new COMMON::InputNotifyUsers());
	AllObjects.Add(1323865418, new COMMON::InputNotifyChats());
	AllObjects.Add(-2034751068, new COMMON::InputNotifyAll());
	AllObjects.Add(-664522512, new COMMON::InputPeerNotifyEventsEmpty());
	AllObjects.Add(1949068008, new COMMON::InputPeerNotifyEventsAll());
	AllObjects.Add(-1302424776, new COMMON::InputPeerNotifySettings());
	AllObjects.Add(-1287858771, new COMMON::PeerNotifyEventsEmpty());
	AllObjects.Add(-1997726355, new COMMON::PeerNotifyEventsAll());
	AllObjects.Add(310748784, new COMMON::PeerNotifySettingsEmpty());
	AllObjects.Add(-1062941286, new COMMON::PeerNotifySettings());
	AllObjects.Add(-853113727, new COMMON::PeerSettings());
	AllObjects.Add(1463201996, new COMMON::WallPaper());
	AllObjects.Add(612307299, new COMMON::WallPaperSolid());
	AllObjects.Add(-1194665128, new COMMON::InputReportReasonSpam());
	AllObjects.Add(-1916329442, new COMMON::InputReportReasonViolence());
	AllObjects.Add(584669486, new COMMON::InputReportReasonPornography());
	AllObjects.Add(174945505, new COMMON::InputReportReasonOther());
	AllObjects.Add(64, new COMMON::UserFull());
	AllObjects.Add(-1798761991, new COMMON::Contact());
	AllObjects.Add(948175568, new COMMON::ImportedContact());
	AllObjects.Add(2043157334, new COMMON::ContactBlocked());
	AllObjects.Add(1628203219, new COMMON::ContactStatus());
	AllObjects.Add(1279839802, new CONTACTS::Link());
	AllObjects.Add(-760656969, new CONTACTS::ContactsNotModified());
	AllObjects.Add(1115613418, new CONTACTS::Contacts());
	AllObjects.Add(991744119, new CONTACTS::ImportedContacts());
	AllObjects.Add(361567004, new CONTACTS::Blocked());
	AllObjects.Add(-1593702256, new CONTACTS::BlockedSlice());
	AllObjects.Add(1080867349, new MESSAGES::Dialogs());
	AllObjects.Add(-208347023, new MESSAGES::DialogsSlice());
	AllObjects.Add(-2020707956, new MESSAGES::Messages());
	AllObjects.Add(64, new MESSAGES::MessagesSlice());
	AllObjects.Add(925771417, new MESSAGES::ChannelMessages());
	AllObjects.Add(-710934684, new MESSAGES::Chats());
	AllObjects.Add(1142020252, new MESSAGES::ChatsSlice());
	AllObjects.Add(-1663969307, new MESSAGES::ChatFull());
	AllObjects.Add(-781624140, new MESSAGES::AffectedHistory());
	AllObjects.Add(1828119127, new COMMON::InputMessagesFilterEmpty());
	AllObjects.Add(480577942, new COMMON::InputMessagesFilterPhotos());
	AllObjects.Add(1695465631, new COMMON::InputMessagesFilterVideo());
	AllObjects.Add(-453973674, new COMMON::InputMessagesFilterPhotoVideo());
	AllObjects.Add(-1150066983, new COMMON::InputMessagesFilterPhotoVideoDocuments());
	AllObjects.Add(-1997415010, new COMMON::InputMessagesFilterDocument());
	AllObjects.Add(-2015498114, new COMMON::InputMessagesFilterUrl());
	AllObjects.Add(-2023372545, new COMMON::InputMessagesFilterGif());
	AllObjects.Add(-1832651440, new COMMON::InputMessagesFilterVoice());
	AllObjects.Add(-1632349897, new COMMON::InputMessagesFilterMusic());
	AllObjects.Add(-1192484806, new COMMON::InputMessagesFilterChatPhotos());
	AllObjects.Add(1754777984, new COMMON::InputMessagesFilterPhoneCalls());
	AllObjects.Add(-1541964678, new COMMON::InputMessagesFilterRoundVoice());
	AllObjects.Add(1406814645, new COMMON::InputMessagesFilterRoundVideo());
	AllObjects.Add(-1696139071, new COMMON::InputMessagesFilterMyMentions());
	AllObjects.Add(-49665249, new COMMON::UpdateNewMessage());
	AllObjects.Add(-692088754, new COMMON::UpdateMessageID());
	AllObjects.Add(-441447006, new COMMON::UpdateDeleteMessages());
	AllObjects.Add(661211228, new COMMON::UpdateUserTyping());
	AllObjects.Add(535455130, new COMMON::UpdateChatUserTyping());
	AllObjects.Add(64, new COMMON::UpdateChatParticipants());
	AllObjects.Add(601422619, new COMMON::UpdateUserStatus());
	AllObjects.Add(1932211111, new COMMON::UpdateUserName());
	AllObjects.Add(205205909, new COMMON::UpdateUserPhoto());
	AllObjects.Add(-1178897115, new COMMON::UpdateContactRegistered());
	AllObjects.Add(-983093603, new COMMON::UpdateContactLink());
	AllObjects.Add(-1698841582, new COMMON::UpdateNewEncryptedMessage());
	AllObjects.Add(1458638871, new COMMON::UpdateEncryptedChatTyping());
	AllObjects.Add(-1914133836, new COMMON::UpdateEncryption());
	AllObjects.Add(-1222246856, new COMMON::UpdateEncryptedMessagesRead());
	AllObjects.Add(1544440810, new COMMON::UpdateChatParticipantAdd());
	AllObjects.Add(579624814, new COMMON::UpdateChatParticipantDelete());
	AllObjects.Add(1939365518, new COMMON::UpdateDcOptions());
	AllObjects.Add(451472512, new COMMON::UpdateUserBlocked());
	AllObjects.Add(-278347074, new COMMON::UpdateNotifySettings());
	AllObjects.Add(426304747, new COMMON::UpdateServiceNotification());
	AllObjects.Add(707214318, new COMMON::UpdatePrivacy());
	AllObjects.Add(2067904786, new COMMON::UpdateUserPhone());
	AllObjects.Add(1560109465, new COMMON::UpdateReadHistoryInbox());
	AllObjects.Add(-1088344273, new COMMON::UpdateReadHistoryOutbox());
	AllObjects.Add(319981951, new COMMON::UpdateWebPage());
	AllObjects.Add(859423080, new COMMON::UpdateReadMessagesContents());
	AllObjects.Add(-77134613, new COMMON::UpdateChannelTooLong());
	AllObjects.Add(1448531126, new COMMON::UpdateChannel());
	AllObjects.Add(-654001566, new COMMON::UpdateNewChannelMessage());
	AllObjects.Add(2146636866, new COMMON::UpdateReadChannelInbox());
	AllObjects.Add(-920554045, new COMMON::UpdateDeleteChannelMessages());
	AllObjects.Add(1261150616, new COMMON::UpdateChannelMessageViews());
	AllObjects.Add(1098486894, new COMMON::UpdateChatAdmins());
	AllObjects.Add(1494847670, new COMMON::UpdateChatParticipantAdmin());
	AllObjects.Add(-1439659416, new COMMON::UpdateNewStickerSet());
	AllObjects.Add(64, new COMMON::UpdateStickerSetsOrder());
	AllObjects.Add(-331502013, new COMMON::UpdateStickerSets());
	AllObjects.Add(506754451, new COMMON::UpdateSavedGifs());
	AllObjects.Add(-1872330156, new COMMON::UpdateBotInlineQuery());
	AllObjects.Add(64, new COMMON::UpdateBotInlineSend());
	AllObjects.Add(-145932517, new COMMON::UpdateEditChannelMessage());
	AllObjects.Add(1965316504, new COMMON::UpdateChannelPinnedMessage());
	AllObjects.Add(-515426841, new COMMON::UpdateBotCallbackQuery());
	AllObjects.Add(-1552940060, new COMMON::UpdateEditMessage());
	AllObjects.Add(1517998841, new COMMON::UpdateInlineBotCallbackQuery());
	AllObjects.Add(-943073755, new COMMON::UpdateReadChannelOutbox());
	AllObjects.Add(1773743086, new COMMON::UpdateDraftMessage());
	AllObjects.Add(1109859671, new COMMON::UpdateReadFeaturedStickers());
	AllObjects.Add(539771546, new COMMON::UpdateRecentStickers());
	AllObjects.Add(115157410, new COMMON::UpdateConfig());
	AllObjects.Add(-1889053645, new COMMON::UpdatePtsChanged());
	AllObjects.Add(1668928, new COMMON::UpdateChannelWebPage());
	AllObjects.Add(-861793833, new COMMON::UpdateDialogPinned());
	AllObjects.Add(-1913206056, new COMMON::UpdatePinnedDialogs());
	AllObjects.Add(-1010821245, new COMMON::UpdateBotWebhookJSON());
	AllObjects.Add(-1505717605, new COMMON::UpdateBotWebhookJSONQuery());
	AllObjects.Add(1086967264, new COMMON::UpdateBotShippingQuery());
	AllObjects.Add(-1455804579, new COMMON::UpdateBotPrecheckoutQuery());
	AllObjects.Add(510332843, new COMMON::UpdatePhoneCall());
	AllObjects.Add(1262535184, new COMMON::UpdateLangPackTooLong());
	AllObjects.Add(1294926422, new COMMON::UpdateLangPack());
	AllObjects.Add(1838748133, new COMMON::UpdateFavedStickers());
	AllObjects.Add(1161529737, new COMMON::UpdateChannelReadMessagesContents());
	AllObjects.Add(-1096317840, new COMMON::UpdateContactsReset());
	AllObjects.Add(1042967717, new UPDATES::State());
	AllObjects.Add(950105437, new UPDATES::DifferenceEmpty());
	AllObjects.Add(10525940, new UPDATES::Difference());
	AllObjects.Add(-2129003608, new UPDATES::DifferenceSlice());
	AllObjects.Add(1838153290, new UPDATES::DifferenceTooLong());
	AllObjects.Add(2125404131, new COMMON::UpdatesTooLong());
	AllObjects.Add(297750417, new COMMON::UpdateShortMessage());
	AllObjects.Add(-2010742506, new COMMON::UpdateShortChatMessage());
	AllObjects.Add(-1042361224, new COMMON::UpdateShort());
	AllObjects.Add(-1023124622, new COMMON::UpdatesCombined());
	AllObjects.Add(1078111860, new COMMON::Updates());
	AllObjects.Add(473166097, new COMMON::UpdateShortSentMessage());
	AllObjects.Add(-1519727987, new PHOTOS::Photos());
	AllObjects.Add(1411319061, new PHOTOS::PhotosSlice());
	AllObjects.Add(-1473502944, new PHOTOS::Photo());
	AllObjects.Add(64, new UPLOAD::File());
	AllObjects.Add(1526616810, new UPLOAD::FileCdnRedirect());
	AllObjects.Add(64, new COMMON::DcOption());
	AllObjects.Add(-1535708275, new COMMON::Config());
	AllObjects.Add(1964448398, new COMMON::NearestDc());
	AllObjects.Add(301172617, new HELP::AppUpdate());
	AllObjects.Add(912612036, new HELP::NoAppUpdate());
	AllObjects.Add(2023738136, new HELP::InviteText());
	AllObjects.Add(-1597997397, new COMMON::EncryptedChatEmpty());
	AllObjects.Add(-603719877, new COMMON::EncryptedChatWaiting());
	AllObjects.Add(2119334088, new COMMON::EncryptedChatRequested());
	AllObjects.Add(919492346, new COMMON::EncryptedChat());
	AllObjects.Add(668849683, new COMMON::EncryptedChatDiscarded());
	AllObjects.Add(-508214799, new COMMON::InputEncryptedChat());
	AllObjects.Add(2118721474, new COMMON::EncryptedFileEmpty());
	AllObjects.Add(1285124170, new COMMON::EncryptedFile());
	AllObjects.Add(1690515224, new COMMON::InputEncryptedFileEmpty());
	AllObjects.Add(100908388, new COMMON::InputEncryptedFileUploaded());
	AllObjects.Add(-441116838, new COMMON::InputEncryptedFile());
	AllObjects.Add(-931938003, new COMMON::InputEncryptedFileBigUploaded());
	AllObjects.Add(415308013, new COMMON::EncryptedMessage());
	AllObjects.Add(105607971, new COMMON::EncryptedMessageService());
	AllObjects.Add(893838016, new MESSAGES::DhConfigNotModified());
	AllObjects.Add(-585227732, new MESSAGES::DhConfig());
	AllObjects.Add(898174806, new MESSAGES::SentEncryptedMessage());
	AllObjects.Add(855610260, new MESSAGES::SentEncryptedFile());
	AllObjects.Add(-1360334734, new COMMON::InputDocumentEmpty());
	AllObjects.Add(1384741144, new COMMON::InputDocument());
	AllObjects.Add(1908996150, new COMMON::DocumentEmpty());
	AllObjects.Add(-953474169, new COMMON::Document());
	AllObjects.Add(-155859433, new HELP::Support());
	AllObjects.Add(-670313313, new COMMON::NotifyPeer());
	AllObjects.Add(1278986420, new COMMON::NotifyUsers());
	AllObjects.Add(-1009907776, new COMMON::NotifyChats());
	AllObjects.Add(1618792564, new COMMON::NotifyAll());
	AllObjects.Add(1316273942, new COMMON::SendMessageTypingAction());
	AllObjects.Add(-171417859, new COMMON::SendMessageCancelAction());
	AllObjects.Add(1876330401, new COMMON::SendMessageRecordVideoAction());
	AllObjects.Add(-331712791, new COMMON::SendMessageUploadVideoAction());
	AllObjects.Add(-143446059, new COMMON::SendMessageRecordAudioAction());
	AllObjects.Add(-1411952141, new COMMON::SendMessageUploadAudioAction());
	AllObjects.Add(642438097, new COMMON::SendMessageUploadPhotoAction());
	AllObjects.Add(-455537494, new COMMON::SendMessageUploadDocumentAction());
	AllObjects.Add(-1584697577, new COMMON::SendMessageGeoLocationAction());
	AllObjects.Add(1874627682, new COMMON::SendMessageChooseContactAction());
	AllObjects.Add(1217358557, new COMMON::SendMessageGamePlayAction());
	AllObjects.Add(-1132465528, new COMMON::SendMessageRecordRoundAction());
	AllObjects.Add(1713126948, new COMMON::SendMessageUploadRoundAction());
	AllObjects.Add(-2064146150, new CONTACTS::Found());
	AllObjects.Add(415995471, new COMMON::InputPrivacyKeyStatusTimestamp());
	AllObjects.Add(637860797, new COMMON::InputPrivacyKeyChatInvite());
	AllObjects.Add(1608301306, new COMMON::InputPrivacyKeyPhoneCall());
	AllObjects.Add(816524988, new COMMON::PrivacyKeyStatusTimestamp());
	AllObjects.Add(-93516208, new COMMON::PrivacyKeyChatInvite());
	AllObjects.Add(2066441789, new COMMON::PrivacyKeyPhoneCall());
	AllObjects.Add(64, new COMMON::InputPrivacyValueAllowContacts());
	AllObjects.Add(-835368168, new COMMON::InputPrivacyValueAllowAll());
	AllObjects.Add(2143689747, new COMMON::InputPrivacyValueAllowUsers());
	AllObjects.Add(64, new COMMON::InputPrivacyValueDisallowContacts());
	AllObjects.Add(-916034602, new COMMON::InputPrivacyValueDisallowAll());
	AllObjects.Add(1728319888, new COMMON::InputPrivacyValueDisallowUsers());
	AllObjects.Add(-1407451393, new COMMON::PrivacyValueAllowContacts());
	AllObjects.Add(-2105851291, new COMMON::PrivacyValueAllowAll());
	AllObjects.Add(213801805, new COMMON::PrivacyValueAllowUsers());
	AllObjects.Add(452626680, new COMMON::PrivacyValueDisallowContacts());
	AllObjects.Add(1676112779, new COMMON::PrivacyValueDisallowAll());
	AllObjects.Add(64, new COMMON::PrivacyValueDisallowUsers());
	AllObjects.Add(1874545237, new ACCOUNT::PrivacyRules());
	AllObjects.Add(-542125896, new COMMON::AccountDaysTTL());
	AllObjects.Add(1556166508, new COMMON::DocumentAttributeImageSize());
	AllObjects.Add(965326097, new COMMON::DocumentAttributeAnimated());
	AllObjects.Add(316021091, new COMMON::DocumentAttributeSticker());
	AllObjects.Add(64, new COMMON::DocumentAttributeVideo());
	AllObjects.Add(-956738920, new COMMON::DocumentAttributeAudio());
	AllObjects.Add(1744853269, new COMMON::DocumentAttributeFilename());
	AllObjects.Add(-137231976, new COMMON::DocumentAttributeHasStickers());
	AllObjects.Add(580547825, new MESSAGES::StickersNotModified());
	AllObjects.Add(852332170, new MESSAGES::Stickers());
	AllObjects.Add(-728124910, new COMMON::StickerPack());
	AllObjects.Add(-1023252760, new MESSAGES::AllStickersNotModified());
	AllObjects.Add(1598094829, new MESSAGES::AllStickers());
	AllObjects.Add(611279790, new COMMON::DisabledFeature());
	AllObjects.Add(-2054041212, new MESSAGES::AffectedMessages());
	AllObjects.Add(1200770911, new COMMON::ContactLinkUnknown());
	AllObjects.Add(-1378619906, new COMMON::ContactLinkNone());
	AllObjects.Add(1497337638, new COMMON::ContactLinkHasPhone());
	AllObjects.Add(-792591659, new COMMON::ContactLinkContact());
	AllObjects.Add(-394849045, new COMMON::WebPageEmpty());
	AllObjects.Add(484083397, new COMMON::WebPagePending());
	AllObjects.Add(-1129052321, new COMMON::WebPage());
	AllObjects.Add(1939113093, new COMMON::WebPageNotModified());
	AllObjects.Add(-152636805, new COMMON::Authorization());
	AllObjects.Add(-559198190, new ACCOUNT::Authorizations());
	AllObjects.Add(415029910, new ACCOUNT::NoPassword());
	AllObjects.Add(471079036, new ACCOUNT::Password());
	AllObjects.Add(-1289046089, new ACCOUNT::PasswordSettings());
	AllObjects.Add(-345140858, new ACCOUNT::PasswordInputSettings());
	AllObjects.Add(-1521977069, new AUTH::PasswordRecovery());
	AllObjects.Add(2042070179, new COMMON::ReceivedNotifyMessage());
	AllObjects.Add(1765269353, new COMMON::ChatInviteEmpty());
	AllObjects.Add(-1140510980, new COMMON::ChatInviteExported());
	AllObjects.Add(2087544922, new COMMON::ChatInviteAlready());
	AllObjects.Add(1492481243, new COMMON::ChatInvite());
	AllObjects.Add(-1792297217, new COMMON::InputStickerSetEmpty());
	AllObjects.Add(1772283805, new COMMON::InputStickerSetID());
	AllObjects.Add(-1597498234, new COMMON::InputStickerSetShortName());
	AllObjects.Add(1094398157, new COMMON::StickerSet());
	AllObjects.Add(-1507587402, new MESSAGES::StickerSet());
	AllObjects.Add(-943162686, new COMMON::BotCommand());
	AllObjects.Add(975038616, new COMMON::BotInfo());
	AllObjects.Add(-2142700894, new COMMON::KeyboardButton());
	AllObjects.Add(100633125, new COMMON::KeyboardButtonUrl());
	AllObjects.Add(1180580456, new COMMON::KeyboardButtonCallback());
	AllObjects.Add(694971057, new COMMON::KeyboardButtonRequestPhone());
	AllObjects.Add(1064008188, new COMMON::KeyboardButtonRequestGeoLocation());
	AllObjects.Add(64, new COMMON::KeyboardButtonSwitchInline());
	AllObjects.Add(-820186032, new COMMON::KeyboardButtonGame());
	AllObjects.Add(-1153443409, new COMMON::KeyboardButtonBuy());
	AllObjects.Add(-2088017801, new COMMON::KeyboardButtonRow());
	AllObjects.Add(-2057617760, new COMMON::ReplyKeyboardHide());
	AllObjects.Add(-1601564428, new COMMON::ReplyKeyboardForceReply());
	AllObjects.Add(-1938488779, new COMMON::ReplyKeyboardMarkup());
	AllObjects.Add(1409459016, new COMMON::ReplyInlineMarkup());
	AllObjects.Add(-1782934853, new COMMON::MessageEntityUnknown());
	AllObjects.Add(-1655241478, new COMMON::MessageEntityMention());
	AllObjects.Add(224093039, new COMMON::MessageEntityHashtag());
	AllObjects.Add(-947196052, new COMMON::MessageEntityBotCommand());
	AllObjects.Add(942002286, new COMMON::MessageEntityUrl());
	AllObjects.Add(-1032461212, new COMMON::MessageEntityEmail());
	AllObjects.Add(-922000963, new COMMON::MessageEntityBold());
	AllObjects.Add(1619750786, new COMMON::MessageEntityItalic());
	AllObjects.Add(1896194600, new COMMON::MessageEntityCode());
	AllObjects.Add(-531918221, new COMMON::MessageEntityPre());
	AllObjects.Add(668182134, new COMMON::MessageEntityTextUrl());
	AllObjects.Add(1489644853, new COMMON::MessageEntityMentionName());
	AllObjects.Add(-915894752, new COMMON::InputMessageEntityMentionName());
	AllObjects.Add(-2044818194, new COMMON::InputChannelEmpty());
	AllObjects.Add(779217839, new COMMON::InputChannel());
	AllObjects.Add(-646314113, new CONTACTS::ResolvedPeer());
	AllObjects.Add(64, new COMMON::MessageRange());
	AllObjects.Add(-72412866, new UPDATES::ChannelDifferenceEmpty());
	AllObjects.Add(897293674, new UPDATES::ChannelDifferenceTooLong());
	AllObjects.Add(1315398688, new UPDATES::ChannelDifference());
	AllObjects.Add(-416361324, new COMMON::ChannelMessagesFilterEmpty());
	AllObjects.Add(1473869773, new COMMON::ChannelMessagesFilter());
	AllObjects.Add(497871637, new COMMON::ChannelParticipant());
	AllObjects.Add(1838819491, new COMMON::ChannelParticipantSelf());
	AllObjects.Add(-102636829, new COMMON::ChannelParticipantCreator());
	AllObjects.Add(-1733808216, new COMMON::ChannelParticipantAdmin());
	AllObjects.Add(-2045236190, new COMMON::ChannelParticipantBanned());
	AllObjects.Add(2033991646, new COMMON::ChannelParticipantsRecent());
	AllObjects.Add(1770610868, new COMMON::ChannelParticipantsAdmins());
	AllObjects.Add(-2058766941, new COMMON::ChannelParticipantsKicked());
	AllObjects.Add(1535562160, new COMMON::ChannelParticipantsBots());
	AllObjects.Add(-509270252, new COMMON::ChannelParticipantsBanned());
	AllObjects.Add(64, new COMMON::ChannelParticipantsSearch());
	AllObjects.Add(-1461555467, new CHANNELS::ChannelParticipants());
	AllObjects.Add(1672600016, new CHANNELS::ChannelParticipant());
	AllObjects.Add(-1874923791, new HELP::TermsOfService());
	AllObjects.Add(533474838, new COMMON::FoundGif());
	AllObjects.Add(151287196, new COMMON::FoundGifCached());
	AllObjects.Add(169609797, new MESSAGES::FoundGifs());
	AllObjects.Add(-1571028248, new MESSAGES::SavedGifsNotModified());
	AllObjects.Add(-1526134994, new MESSAGES::SavedGifs());
	AllObjects.Add(334311209, new COMMON::InputBotInlineMessageMediaAuto());
	AllObjects.Add(-2021995203, new COMMON::InputBotInlineMessageText());
	AllObjects.Add(-509762060, new COMMON::InputBotInlineMessageMediaGeo());
	AllObjects.Add(-928141398, new COMMON::InputBotInlineMessageMediaVenue());
	AllObjects.Add(-1493061843, new COMMON::InputBotInlineMessageMediaContact());
	AllObjects.Add(1683505739, new COMMON::InputBotInlineMessageGame());
	AllObjects.Add(1524742956, new COMMON::InputBotInlineResult());
	AllObjects.Add(-1486563160, new COMMON::InputBotInlineResultPhoto());
	AllObjects.Add(-989988609, new COMMON::InputBotInlineResultDocument());
	AllObjects.Add(-233331633, new COMMON::InputBotInlineResultGame());
	AllObjects.Add(64, new COMMON::BotInlineMessageMediaAuto());
	AllObjects.Add(-496664692, new COMMON::BotInlineMessageText());
	AllObjects.Add(-1193767110, new COMMON::BotInlineMessageMediaGeo());
	AllObjects.Add(774071875, new COMMON::BotInlineMessageMediaVenue());
	AllObjects.Add(-726340299, new COMMON::BotInlineMessageMediaContact());
	AllObjects.Add(-1179718757, new COMMON::BotInlineResult());
	AllObjects.Add(194304791, new COMMON::BotInlineMediaResult());
	AllObjects.Add(1029100492, new MESSAGES::BotResults());
	AllObjects.Add(57165855, new COMMON::ExportedMessageLink());
	AllObjects.Add(-1393238022, new COMMON::MessageFwdHeader());
	AllObjects.Add(-1944738958, new AUTH::CodeTypeSms());
	AllObjects.Add(-472703884, new AUTH::CodeTypeCall());
	AllObjects.Add(-70357982, new AUTH::CodeTypeFlashCall());
	AllObjects.Add(-2040939715, new AUTH::SentCodeTypeApp());
	AllObjects.Add(-1564802880, new AUTH::SentCodeTypeSms());
	AllObjects.Add(-1478143149, new AUTH::SentCodeTypeCall());
	AllObjects.Add(-641334357, new AUTH::SentCodeTypeFlashCall());
	AllObjects.Add(-1537320906, new MESSAGES::BotCallbackAnswer());
	AllObjects.Add(-421677786, new MESSAGES::MessageEditData());
	AllObjects.Add(-1992487799, new COMMON::InputBotInlineMessageID());
	AllObjects.Add(-1620959172, new COMMON::InlineBotSwitchPM());
	AllObjects.Add(1422094643, new MESSAGES::PeerDialogs());
	AllObjects.Add(1539362285, new COMMON::TopPeer());
	AllObjects.Add(1528522411, new COMMON::TopPeerCategoryBotsPM());
	AllObjects.Add(-495483372, new COMMON::TopPeerCategoryBotsInline());
	AllObjects.Add(64, new COMMON::TopPeerCategoryCorrespondents());
	AllObjects.Add(1252071357, new COMMON::TopPeerCategoryGroups());
	AllObjects.Add(680926486, new COMMON::TopPeerCategoryChannels());
	AllObjects.Add(-1935182306, new COMMON::TopPeerCategoryPhoneCalls());
	AllObjects.Add(-1857911813, new COMMON::TopPeerCategoryPeers());
	AllObjects.Add(-177330466, new CONTACTS::TopPeersNotModified());
	AllObjects.Add(-1468876944, new CONTACTS::TopPeers());
	AllObjects.Add(-978433094, new COMMON::DraftMessageEmpty());
	AllObjects.Add(527535869, new COMMON::DraftMessage());
	AllObjects.Add(64, new MESSAGES::FeaturedStickersNotModified());
	AllObjects.Add(-444031496, new MESSAGES::FeaturedStickers());
	AllObjects.Add(64, new MESSAGES::RecentStickersNotModified());
	AllObjects.Add(1879695964, new MESSAGES::RecentStickers());
	AllObjects.Add(-928396465, new MESSAGES::ArchivedStickers());
	AllObjects.Add(672556088, new MESSAGES::StickerSetInstallResultSuccess());
	AllObjects.Add(-1475288011, new MESSAGES::StickerSetInstallResultArchive());
	AllObjects.Add(-760934300, new COMMON::StickerSetCovered());
	AllObjects.Add(467994420, new COMMON::StickerSetMultiCovered());
	AllObjects.Add(-1294215506, new COMMON::MaskCoords());
	AllObjects.Add(1461819722, new COMMON::InputStickeredMediaPhoto());
	AllObjects.Add(64, new COMMON::InputStickeredMediaDocument());
	AllObjects.Add(996538813, new COMMON::Game());
	AllObjects.Add(64, new COMMON::InputGameID());
	AllObjects.Add(182989251, new COMMON::InputGameShortName());
	AllObjects.Add(-788725928, new COMMON::HighScore());
	AllObjects.Add(-1711457382, new MESSAGES::HighScores());
	AllObjects.Add(1333935580, new COMMON::TextEmpty());
	AllObjects.Add(-527153548, new COMMON::TextPlain());
	AllObjects.Add(-995416985, new COMMON::TextBold());
	AllObjects.Add(-1666903335, new COMMON::TextItalic());
	AllObjects.Add(-1004394815, new COMMON::TextUnderline());
	AllObjects.Add(-1782843237, new COMMON::TextStrike());
	AllObjects.Add(-1189527700, new COMMON::TextFixed());
	AllObjects.Add(-1048303556, new COMMON::TextUrl());
	AllObjects.Add(-703767842, new COMMON::TextEmail());
	AllObjects.Add(-681549186, new COMMON::TextConcat());
	AllObjects.Add(-1971431917, new COMMON::PageBlockUnsupported());
	AllObjects.Add(-37508240, new COMMON::PageBlockTitle());
	AllObjects.Add(530250383, new COMMON::PageBlockSubtitle());
	AllObjects.Add(-521818182, new COMMON::PageBlockAuthorDate());
	AllObjects.Add(-328937281, new COMMON::PageBlockHeader());
	AllObjects.Add(-508154895, new COMMON::PageBlockSubheader());
	AllObjects.Add(1711766086, new COMMON::PageBlockParagraph());
	AllObjects.Add(1054437568, new COMMON::PageBlockPreformatted());
	AllObjects.Add(-1727428792, new COMMON::PageBlockFooter());
	AllObjects.Add(-2001657637, new COMMON::PageBlockDivider());
	AllObjects.Add(-1338569266, new COMMON::PageBlockAnchor());
	AllObjects.Add(-188262342, new COMMON::PageBlockList());
	AllObjects.Add(645676326, new COMMON::PageBlockBlockquote());
	AllObjects.Add(-749321137, new COMMON::PageBlockPullquote());
	AllObjects.Add(-2103851287, new COMMON::PageBlockPhoto());
	AllObjects.Add(1712904153, new COMMON::PageBlockVideo());
	AllObjects.Add(3404345, new COMMON::PageBlockCover());
	AllObjects.Add(-788471091, new COMMON::PageBlockEmbed());
	AllObjects.Add(-377803735, new COMMON::PageBlockEmbedPost());
	AllObjects.Add(64, new COMMON::PageBlockCollage());
	AllObjects.Add(1669925907, new COMMON::PageBlockSlideshow());
	AllObjects.Add(-1252976657, new COMMON::PageBlockChannel());
	AllObjects.Add(2132457521, new COMMON::PageBlockAudio());
	AllObjects.Add(-1096925298, new COMMON::PagePart());
	AllObjects.Add(-1429770667, new COMMON::PageFull());
	AllObjects.Add(19129477, new COMMON::PhoneCallDiscardReasonMissed());
	AllObjects.Add(-1597925920, new COMMON::PhoneCallDiscardReasonDisconnect());
	AllObjects.Add(-1866027689, new COMMON::PhoneCallDiscardReasonHangup());
	AllObjects.Add(-907479046, new COMMON::PhoneCallDiscardReasonBusy());
	AllObjects.Add(76379261, new COMMON::DataJSON());
	AllObjects.Add(-127194677, new COMMON::LabeledPrice());
	AllObjects.Add(1487080131, new COMMON::Invoice());
	AllObjects.Add(2126643946, new COMMON::PaymentCharge());
	AllObjects.Add(-341144546, new COMMON::PostAddress());
	AllObjects.Add(-1807770480, new COMMON::PaymentRequestedInfo());
	AllObjects.Add(528138957, new COMMON::PaymentSavedCredentialsCard());
	AllObjects.Add(-657777978, new COMMON::WebDocument());
	AllObjects.Add(1296297371, new COMMON::InputWebDocument());
	AllObjects.Add(-2032780862, new COMMON::InputWebFileLocation());
	AllObjects.Add(-1135352031, new UPLOAD::WebFile());
	AllObjects.Add(-1548855745, new PAYMENTS::PaymentForm());
	AllObjects.Add(-2095561263, new PAYMENTS::ValidatedRequestedInfo());
	AllObjects.Add(226582350, new PAYMENTS::PaymentResult());
	AllObjects.Add(565794411, new PAYMENTS::PaymentVerficationNeeded());
	AllObjects.Add(-518977200, new PAYMENTS::PaymentReceipt());
	AllObjects.Add(1021612027, new PAYMENTS::SavedInfo());
	AllObjects.Add(-810414399, new COMMON::InputPaymentCredentialsSaved());
	AllObjects.Add(685184820, new COMMON::InputPaymentCredentials());
	AllObjects.Add(889021659, new ACCOUNT::TmpPassword());
	AllObjects.Add(-549707338, new COMMON::ShippingOption());
	AllObjects.Add(-1767595777, new COMMON::InputStickerSetItem());
	AllObjects.Add(-302172642, new COMMON::InputPhoneCall());
	AllObjects.Add(365520467, new COMMON::PhoneCallEmpty());
	AllObjects.Add(-783642853, new COMMON::PhoneCallWaiting());
	AllObjects.Add(-467896701, new COMMON::PhoneCallRequested());
	AllObjects.Add(1060962413, new COMMON::PhoneCallAccepted());
	AllObjects.Add(1739319039, new COMMON::PhoneCall());
	AllObjects.Add(-514995632, new COMMON::PhoneCallDiscarded());
	AllObjects.Add(-1072214883, new COMMON::PhoneConnection());
	AllObjects.Add(-885671006, new COMMON::PhoneCallProtocol());
	AllObjects.Add(1088520940, new PHONE::PhoneCall());
	AllObjects.Add(1860479214, new UPLOAD::CdnFileReuploadNeeded());
	AllObjects.Add(1338679209, new UPLOAD::CdnFile());
	AllObjects.Add(-1159036215, new COMMON::CdnPublicKey());
	AllObjects.Add(182723927, new COMMON::CdnConfig());
	AllObjects.Add(-159264310, new COMMON::LangPackString());
	AllObjects.Add(-1616099476, new COMMON::LangPackStringPluralized());
	AllObjects.Add(-1292994263, new COMMON::LangPackStringDeleted());
	AllObjects.Add(-155089421, new COMMON::LangPackDifference());
	AllObjects.Add(-241666543, new COMMON::LangPackLanguage());
	AllObjects.Add(-1511293859, new COMMON::ChannelAdminRights());
	AllObjects.Add(1229115224, new COMMON::ChannelBannedRights());
	AllObjects.Add(632872934, new COMMON::ChannelAdminLogEventActionChangeTitle());
	AllObjects.Add(780802133, new COMMON::ChannelAdminLogEventActionChangeAbout());
	AllObjects.Add(956058218, new COMMON::ChannelAdminLogEventActionChangeUsername());
	AllObjects.Add(-1017827400, new COMMON::ChannelAdminLogEventActionChangePhoto());
	AllObjects.Add(-1375241957, new COMMON::ChannelAdminLogEventActionToggleInvites());
	AllObjects.Add(1896459814, new COMMON::ChannelAdminLogEventActionToggleSignatures());
	AllObjects.Add(405596393, new COMMON::ChannelAdminLogEventActionUpdatePinned());
	AllObjects.Add(86285168, new COMMON::ChannelAdminLogEventActionEditMessage());
	AllObjects.Add(-1152917438, new COMMON::ChannelAdminLogEventActionDeleteMessage());
	AllObjects.Add(-750768104, new COMMON::ChannelAdminLogEventActionParticipantJoin());
	AllObjects.Add(-227043336, new COMMON::ChannelAdminLogEventActionParticipantLeave());
	AllObjects.Add(-667673373, new COMMON::ChannelAdminLogEventActionParticipantInvite());
	AllObjects.Add(2117982438, new COMMON::ChannelAdminLogEventActionParticipantToggleBan());
	AllObjects.Add(275212245, new COMMON::ChannelAdminLogEventActionParticipantToggleAdmin());
	AllObjects.Add(-1479883855, new COMMON::ChannelAdminLogEventActionChangeStickerSet());
	AllObjects.Add(1077828155, new COMMON::ChannelAdminLogEvent());
	AllObjects.Add(1308068589, new CHANNELS::AdminLogResults());
	AllObjects.Add(-461762326, new COMMON::ChannelAdminLogEventsFilter());
	AllObjects.Add(1967251804, new COMMON::PopularContact());
	AllObjects.Add(-1882984841, new COMMON::CdnFileHash());
	AllObjects.Add(-744058978, new MESSAGES::FavedStickersNotModified());
	AllObjects.Add(372211699, new MESSAGES::FavedStickers());
	AllObjects.Add(758620107, new COMMON::InvokeAfterMsg());
	AllObjects.Add(-256588739, new COMMON::InvokeAfterMsgs());
	AllObjects.Add(-1508030265, new COMMON::InitConnection());
	AllObjects.Add(218995674, new COMMON::InvokeWithLayer());
	AllObjects.Add(-1218865985, new COMMON::InvokeWithoutUpdates());
	AllObjects.Add(-81926801, new AUTH::CheckPhone());
	AllObjects.Add(-319771002, new AUTH::SendCode());
	AllObjects.Add(880150043, new AUTH::SignUp());
	AllObjects.Add(-2129275460, new AUTH::SignIn());
	AllObjects.Add(1088034647, new AUTH::LogOut());
	AllObjects.Add(437103519, new AUTH::ResetAuthorizations());
	AllObjects.Add(-1759699849, new AUTH::SendInvites());
	AllObjects.Add(-838877211, new AUTH::ExportAuthorization());
	AllObjects.Add(328658915, new AUTH::ImportAuthorization());
	AllObjects.Add(86693069, new AUTH::BindTempAuthKey());
	AllObjects.Add(754951015, new AUTH::ImportBotAuthorization());
	AllObjects.Add(64, new AUTH::CheckPassword());
	AllObjects.Add(1723635672, new AUTH::RequestPasswordRecovery());
	AllObjects.Add(-1838242482, new AUTH::RecoverPassword());
	AllObjects.Add(-1079381698, new AUTH::ResendCode());
	AllObjects.Add(2013594655, new AUTH::CancelCode());
	AllObjects.Add(-2002696050, new AUTH::DropTempAuthKeys());
	AllObjects.Add(2024308323, new ACCOUNT::RegisterDevice());
	AllObjects.Add(1079756133, new ACCOUNT::UnregisterDevice());
	AllObjects.Add(-1822703996, new ACCOUNT::UpdateNotifySettings());
	AllObjects.Add(833467154, new ACCOUNT::GetNotifySettings());
	AllObjects.Add(1192722139, new ACCOUNT::ResetNotifySettings());
	AllObjects.Add(1968656760, new ACCOUNT::UpdateProfile());
	AllObjects.Add(743843942, new ACCOUNT::UpdateStatus());
	AllObjects.Add(-1023783744, new ACCOUNT::GetWallPapers());
	AllObjects.Add(1604130990, new ACCOUNT::ReportPeer());
	AllObjects.Add(1826100263, new ACCOUNT::CheckUsername());
	AllObjects.Add(2094861118, new ACCOUNT::UpdateUsername());
	AllObjects.Add(1355406298, new ACCOUNT::GetPrivacy());
	AllObjects.Add(-400754487, new ACCOUNT::SetPrivacy());
	AllObjects.Add(189697345, new ACCOUNT::DeleteAccount());
	AllObjects.Add(64, new ACCOUNT::GetAccountTTL());
	AllObjects.Add(1581793828, new ACCOUNT::SetAccountTTL());
	AllObjects.Add(64, new ACCOUNT::SendChangePhoneCode());
	AllObjects.Add(-617692304, new ACCOUNT::ChangePhone());
	AllObjects.Add(842391352, new ACCOUNT::UpdateDeviceLocked());
	AllObjects.Add(1489051875, new ACCOUNT::GetAuthorizations());
	AllObjects.Add(-1124894753, new ACCOUNT::ResetAuthorization());
	AllObjects.Add(-181368236, new ACCOUNT::GetPassword());
	AllObjects.Add(-1156477508, new ACCOUNT::GetPasswordSettings());
	AllObjects.Add(-2041873158, new ACCOUNT::UpdatePasswordSettings());
	AllObjects.Add(-1109977579, new ACCOUNT::SendConfirmPhoneCode());
	AllObjects.Add(-1015537313, new ACCOUNT::ConfirmPhone());
	AllObjects.Add(2117239370, new ACCOUNT::GetTmpPassword());
	AllObjects.Add(18, new USERS::GetUsers());
	AllObjects.Add(-1314574134, new USERS::GetFullUser());
	AllObjects.Add(-296508476, new CONTACTS::GetStatuses());
	AllObjects.Add(-1618730048, new CONTACTS::GetContacts());
	AllObjects.Add(-452231124, new CONTACTS::ImportContacts());
	AllObjects.Add(1144493454, new CONTACTS::DeleteContact());
	AllObjects.Add(-1640453287, new CONTACTS::DeleteContacts());
	AllObjects.Add(-62313677, new CONTACTS::Block());
	AllObjects.Add(-1124056603, new CONTACTS::Unblock());
	AllObjects.Add(255163637, new CONTACTS::GetBlocked());
	AllObjects.Add(926410116, new CONTACTS::ExportCard());
	AllObjects.Add(-23666353, new CONTACTS::ImportCard());
	AllObjects.Add(-669845487, new CONTACTS::Search());
	AllObjects.Add(-1546961671, new CONTACTS::ResolveUsername());
	AllObjects.Add(-1255302956, new CONTACTS::GetTopPeers());
	AllObjects.Add(-1401691366, new CONTACTS::ResetTopPeerRating());
	AllObjects.Add(-248015481, new CONTACTS::ResetSaved());
	AllObjects.Add(1962549826, new MESSAGES::GetMessages());
	AllObjects.Add(-978773223, new MESSAGES::GetDialogs());
	AllObjects.Add(1177069999, new MESSAGES::GetHistory());
	AllObjects.Add(64, new MESSAGES::Search());
	AllObjects.Add(64, new MESSAGES::ReadHistory());
	AllObjects.Add(156959004, new MESSAGES::DeleteHistory());
	AllObjects.Add(-761950491, new MESSAGES::DeleteMessages());
	AllObjects.Add(18, new MESSAGES::ReceivedMessages());
	AllObjects.Add(1348371107, new MESSAGES::SetTyping());
	AllObjects.Add(2051180794, new MESSAGES::SendMessage());
	AllObjects.Add(-1855458872, new MESSAGES::SendMedia());
	AllObjects.Add(-1795060112, new MESSAGES::ForwardMessages());
	AllObjects.Add(-611183153, new MESSAGES::ReportSpam());
	AllObjects.Add(-1687096920, new MESSAGES::HideReportSpam());
	AllObjects.Add(-1663012298, new MESSAGES::GetPeerSettings());
	AllObjects.Add(-2019464644, new MESSAGES::GetChats());
	AllObjects.Add(1713144635, new MESSAGES::GetFullChat());
	AllObjects.Add(1428702684, new MESSAGES::EditChatTitle());
	AllObjects.Add(-663139126, new MESSAGES::EditChatPhoto());
	AllObjects.Add(162177273, new MESSAGES::AddChatUser());
	AllObjects.Add(371155424, new MESSAGES::DeleteChatUser());
	AllObjects.Add(64, new MESSAGES::CreateChat());
	AllObjects.Add(-113535437, new MESSAGES::ForwardMessage());
	AllObjects.Add(1351208742, new MESSAGES::GetDhConfig());
	AllObjects.Add(1135562230, new MESSAGES::RequestEncryption());
	AllObjects.Add(352631869, new MESSAGES::AcceptEncryption());
	AllObjects.Add(-987506195, new MESSAGES::DiscardEncryption());
	AllObjects.Add(-313453447, new MESSAGES::SetEncryptedTyping());
	AllObjects.Add(174672767, new MESSAGES::ReadEncryptedHistory());
	AllObjects.Add(1936160681, new MESSAGES::SendEncrypted());
	AllObjects.Add(1713082522, new MESSAGES::SendEncryptedFile());
	AllObjects.Add(-1539713998, new MESSAGES::SendEncryptedService());
	AllObjects.Add(1723573589, new MESSAGES::ReceivedQueue());
	AllObjects.Add(260836427, new MESSAGES::ReportEncryptedSpam());
	AllObjects.Add(2000660278, new MESSAGES::ReadMessageContents());
	AllObjects.Add(-1323788772, new MESSAGES::GetAllStickers());
	AllObjects.Add(608051749, new MESSAGES::GetWebPagePreview());
	AllObjects.Add(-1991079811, new MESSAGES::ExportChatInvite());
	AllObjects.Add(-1145983682, new MESSAGES::CheckChatInvite());
	AllObjects.Add(470110316, new MESSAGES::ImportChatInvite());
	AllObjects.Add(245963046, new MESSAGES::GetStickerSet());
	AllObjects.Add(1625591751, new MESSAGES::InstallStickerSet());
	AllObjects.Add(-564826375, new MESSAGES::UninstallStickerSet());
	AllObjects.Add(2020859878, new MESSAGES::StartBot());
	AllObjects.Add(1571145924, new MESSAGES::GetMessagesViews());
	AllObjects.Add(-505836564, new MESSAGES::ToggleChatAdmins());
	AllObjects.Add(782231209, new MESSAGES::EditChatAdmin());
	AllObjects.Add(-474438891, new MESSAGES::MigrateChat());
	AllObjects.Add(-1330889570, new MESSAGES::SearchGlobal());
	AllObjects.Add(964113272, new MESSAGES::ReorderStickerSets());
	AllObjects.Add(1680117299, new MESSAGES::GetDocumentByHash());
	AllObjects.Add(1803000511, new MESSAGES::SearchGifs());
	AllObjects.Add(1379778435, new MESSAGES::GetSavedGifs());
	AllObjects.Add(-886015438, new MESSAGES::SaveGif());
	AllObjects.Add(-1650897327, new MESSAGES::GetInlineBotResults());
	AllObjects.Add(111304427, new MESSAGES::SetInlineBotResults());
	AllObjects.Add(-33132879, new MESSAGES::SendInlineBotResult());
	AllObjects.Add(915252989, new MESSAGES::GetMessageEditData());
	AllObjects.Add(-890990130, new MESSAGES::EditMessage());
	AllObjects.Add(-2060710893, new MESSAGES::EditInlineBotMessage());
	AllObjects.Add(-325121407, new MESSAGES::GetBotCallbackAnswer());
	AllObjects.Add(169054165, new MESSAGES::SetBotCallbackAnswer());
	AllObjects.Add(-1183410387, new MESSAGES::GetPeerDialogs());
	AllObjects.Add(1273051580, new MESSAGES::SaveDraft());
	AllObjects.Add(1703755626, new MESSAGES::GetAllDrafts());
	AllObjects.Add(1338682413, new MESSAGES::GetFeaturedStickers());
	AllObjects.Add(645992795, new MESSAGES::ReadFeaturedStickers());
	AllObjects.Add(-913137314, new MESSAGES::GetRecentStickers());
	AllObjects.Add(-132634823, new MESSAGES::SaveRecentSticker());
	AllObjects.Add(761305481, new MESSAGES::ClearRecentStickers());
	AllObjects.Add(-1837698729, new MESSAGES::GetArchivedStickers());
	AllObjects.Add(-1614301083, new MESSAGES::GetMaskStickers());
	AllObjects.Add(-865641524, new MESSAGES::GetAttachedStickers());
	AllObjects.Add(-1058211698, new MESSAGES::SetGameScore());
	AllObjects.Add(1688186133, new MESSAGES::SetInlineGameScore());
	AllObjects.Add(-1654381848, new MESSAGES::GetGameHighScores());
	AllObjects.Add(64, new MESSAGES::GetInlineGameHighScores());
	AllObjects.Add(64, new MESSAGES::GetCommonChats());
	AllObjects.Add(-267409173, new MESSAGES::GetAllChats());
	AllObjects.Add(-1852847566, new MESSAGES::GetWebPage());
	AllObjects.Add(1790871858, new MESSAGES::ToggleDialogPin());
	AllObjects.Add(1157013397, new MESSAGES::ReorderPinnedDialogs());
	AllObjects.Add(1322669282, new MESSAGES::GetPinnedDialogs());
	AllObjects.Add(-93128987, new MESSAGES::SetBotShippingResults());
	AllObjects.Add(64, new MESSAGES::SetBotPrecheckoutResults());
	AllObjects.Add(-1312646319, new MESSAGES::UploadMedia());
	AllObjects.Add(552631753, new MESSAGES::SendScreenshotNotification());
	AllObjects.Add(235654689, new MESSAGES::GetFavedStickers());
	AllObjects.Add(1539702713, new MESSAGES::FaveSticker());
	AllObjects.Add(1921275718, new MESSAGES::GetUnreadMentions());
	AllObjects.Add(713610477, new UPDATES::GetState());
	AllObjects.Add(1368822565, new UPDATES::GetDifference());
	AllObjects.Add(64, new UPDATES::GetChannelDifference());
	AllObjects.Add(1381088240, new PHOTOS::UpdateProfilePhoto());
	AllObjects.Add(-1732234673, new PHOTOS::UploadProfilePhoto());
	AllObjects.Add(796905351, new PHOTOS::DeletePhotos());
	AllObjects.Add(-1473065583, new PHOTOS::GetUserPhotos());
	AllObjects.Add(564528307, new UPLOAD::SaveFilePart());
	AllObjects.Add(-1244682525, new UPLOAD::GetFile());
	AllObjects.Add(1030192094, new UPLOAD::SaveBigFilePart());
	AllObjects.Add(-1920866780, new UPLOAD::GetWebFile());
	AllObjects.Add(-1011089376, new UPLOAD::GetCdnFile());
	AllObjects.Add(152893722, new UPLOAD::ReuploadCdnFile());
	AllObjects.Add(2076710391, new UPLOAD::GetCdnFileHashes());
	AllObjects.Add(1796798916, new HELP::GetConfig());
	AllObjects.Add(640725791, new HELP::GetNearestDc());
	AllObjects.Add(-1763627602, new HELP::GetAppUpdate());
	AllObjects.Add(1224147567, new HELP::SaveAppLog());
	AllObjects.Add(1126381901, new HELP::GetInviteText());
	AllObjects.Add(-855056484, new HELP::GetSupport());
	AllObjects.Add(1877938320, new HELP::GetAppChangelog());
	AllObjects.Add(-210763467, new HELP::GetTermsOfService());
	AllObjects.Add(-842063124, new HELP::SetBotUpdatesStatus());
	AllObjects.Add(1116930642, new HELP::GetCdnConfig());
	AllObjects.Add(927535308, new CHANNELS::ReadHistory());
	AllObjects.Add(1325252996, new CHANNELS::DeleteMessages());
	AllObjects.Add(467078609, new CHANNELS::DeleteUserHistory());
	AllObjects.Add(276302078, new CHANNELS::ReportSpam());
	AllObjects.Add(1202968467, new CHANNELS::GetMessages());
	AllObjects.Add(-1836066524, new CHANNELS::GetParticipants());
	AllObjects.Add(-1495831212, new CHANNELS::GetParticipant());
	AllObjects.Add(64, new CHANNELS::GetChannels());
	AllObjects.Add(64, new CHANNELS::GetFullChannel());
	AllObjects.Add(2134739444, new CHANNELS::CreateChannel());
	AllObjects.Add(511697427, new CHANNELS::EditAbout());
	AllObjects.Add(344111136, new CHANNELS::EditAdmin());
	AllObjects.Add(-789811882, new CHANNELS::EditTitle());
	AllObjects.Add(-917033231, new CHANNELS::EditPhoto());
	AllObjects.Add(750642704, new CHANNELS::CheckUsername());
	AllObjects.Add(-558689227, new CHANNELS::UpdateUsername());
	AllObjects.Add(-987450076, new CHANNELS::JoinChannel());
	AllObjects.Add(-1784006920, new CHANNELS::LeaveChannel());
	AllObjects.Add(1815781145, new CHANNELS::InviteToChannel());
	AllObjects.Add(-2063051065, new CHANNELS::ExportInvite());
	AllObjects.Add(-484503104, new CHANNELS::DeleteChannel());
	AllObjects.Add(127098953, new CHANNELS::ToggleInvites());
	AllObjects.Add(768755400, new CHANNELS::ExportMessageLink());
	AllObjects.Add(112617759, new CHANNELS::ToggleSignatures());
	AllObjects.Add(1391275431, new CHANNELS::UpdatePinnedMessage());
	AllObjects.Add(-679309939, new CHANNELS::GetAdminedPublicChannels());
	AllObjects.Add(-854206017, new CHANNELS::EditBanned());
	AllObjects.Add(-2131436237, new CHANNELS::GetAdminLog());
	AllObjects.Add(-106656534, new CHANNELS::SetStickers());
	AllObjects.Add(953988586, new CHANNELS::ReadMessageContents());
	AllObjects.Add(-311875670, new BOTS::SendCustomRequest());
	AllObjects.Add(1295983078, new BOTS::AnswerWebhookJSONQuery());
	AllObjects.Add(1167585433, new PAYMENTS::GetPaymentForm());
	AllObjects.Add(-2136370528, new PAYMENTS::GetPaymentReceipt());
	AllObjects.Add(1955465847, new PAYMENTS::ValidateRequestedInfo());
	AllObjects.Add(-1283880917, new PAYMENTS::SendPaymentForm());
	AllObjects.Add(1266842914, new PAYMENTS::GetSavedInfo());
	AllObjects.Add(-1049608744, new PAYMENTS::ClearSavedInfo());
	AllObjects.Add(1785649307, new STICKERS::CreateStickerSet());
	AllObjects.Add(1359967991, new STICKERS::RemoveStickerFromSet());
	AllObjects.Add(-892029185, new STICKERS::ChangeStickerPosition());
	AllObjects.Add(-1090628730, new STICKERS::AddStickerToSet());
	AllObjects.Add(-1457568427, new PHONE::GetCallConfig());
	AllObjects.Add(-726428325, new PHONE::RequestCall());
	AllObjects.Add(-1598762437, new PHONE::AcceptCall());
	AllObjects.Add(571997742, new PHONE::ConfirmCall());
	AllObjects.Add(1632621847, new PHONE::ReceivedCall());
	AllObjects.Add(-1508649864, new PHONE::DiscardCall());
	AllObjects.Add(879383324, new PHONE::SetCallRating());
	AllObjects.Add(2128443943, new PHONE::SaveCallDebug());
	AllObjects.Add(-1899645542, new LANGPACK::GetLangPack());
	AllObjects.Add(417537582, new LANGPACK::GetStrings());
	AllObjects.Add(64, new LANGPACK::GetDifference());
	AllObjects.Add(2111115136, new LANGPACK::GetLanguages());
