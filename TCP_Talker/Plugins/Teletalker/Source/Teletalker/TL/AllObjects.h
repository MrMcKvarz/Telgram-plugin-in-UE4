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

TMap<int32, TLBaseObject*> TLObjects()
{
	TMap<int32, TLBaseObject*> AllObjects;
	AllObjects.Add(85337187, new COMMON::ResPQ());
	AllObjects.Add(-2083955988, new COMMON::PQInnerData());
	AllObjects.Add(2043348061, new COMMON::ServerDHParamsFail());
	AllObjects.Add(-790100132, new COMMON::ServerDHParamsOk());
	AllObjects.Add(-1249309254, new COMMON::ServerDHInnerData());
	AllObjects.Add(1715713620, new COMMON::ClientDHInnerData());
	AllObjects.Add(1003222836, new COMMON::DhGenOk());
	AllObjects.Add(1188831161, new COMMON::DhGenRetry());
	AllObjects.Add(-1499615742, new COMMON::DhGenFail());
	AllObjects.Add(-161422892, new COMMON::DestroyAuthKeyOk());
	AllObjects.Add(178201177, new COMMON::DestroyAuthKeyNone());
	AllObjects.Add(-368010477, new COMMON::DestroyAuthKeyFail());
	AllObjects.Add(1615239032, new COMMON::ReqPq());
	AllObjects.Add(-686627650, new COMMON::ReqDHParams());
	AllObjects.Add(-184262881, new COMMON::SetClientDHParams());
	AllObjects.Add(-784117408, new COMMON::DestroyAuthKey());
	AllObjects.Add(1658238041, new COMMON::MsgsAck());
	AllObjects.Add(-1477445615, new COMMON::BadMsgNotification());
	AllObjects.Add(-307542917, new COMMON::BadServerSalt());
	AllObjects.Add(-630588590, new COMMON::MsgsStateReq());
	AllObjects.Add(81704317, new COMMON::MsgsStateInfo());
	AllObjects.Add(-1933520591, new COMMON::MsgsAllInfo());
	AllObjects.Add(661470918, new COMMON::MsgDetailedInfo());
	AllObjects.Add(-2137147681, new COMMON::MsgNewDetailedInfo());
	AllObjects.Add(2105940488, new COMMON::MsgResendReq());
	AllObjects.Add(558156313, new COMMON::RpcError());
	AllObjects.Add(1579864942, new COMMON::RpcAnswerUnknown());
	AllObjects.Add(-847714938, new COMMON::RpcAnswerDroppedRunning());
	AllObjects.Add(-1539647305, new COMMON::RpcAnswerDropped());
	AllObjects.Add(155834844, new COMMON::FutureSalt());
	AllObjects.Add(-1370486635, new COMMON::FutureSalts());
	AllObjects.Add(880243653, new COMMON::Pong());
	AllObjects.Add(-501201412, new COMMON::DestroySessionOk());
	AllObjects.Add(1658015945, new COMMON::DestroySessionNone());
	AllObjects.Add(-1631450872, new COMMON::NewSessionCreated());
	AllObjects.Add(-1835453025, new COMMON::HttpWait());
	AllObjects.Add(1940730836, new COMMON::IpPort());
	AllObjects.Add(-644365371, new HELP::ConfigSimple());
	AllObjects.Add(1491380032, new COMMON::RpcDropAnswer());
	AllObjects.Add(-1188971260, new COMMON::GetFutureSalts());
	AllObjects.Add(2059302892, new COMMON::Ping());
	AllObjects.Add(-213746804, new COMMON::PingDelayDisconnect());
	AllObjects.Add(-414113498, new COMMON::DestroySession());
	AllObjects.Add(-1705021803, new CONTEST::SaveDeveloperInfo());
	AllObjects.Add(-1132882121, new COMMON::BoolFalse());
	AllObjects.Add(-1720552011, new COMMON::BoolTrue());
	AllObjects.Add(1072550713, new COMMON::True());
	AllObjects.Add(-994444869, new COMMON::Error());
	AllObjects.Add(1450380236, new COMMON::Null());
	AllObjects.Add(2134579434, new COMMON::InputPeerEmpty());
	AllObjects.Add(2107670217, new COMMON::InputPeerSelf());
	AllObjects.Add(396093539, new COMMON::InputPeerChat());
	AllObjects.Add(2072935910, new COMMON::InputPeerUser());
	AllObjects.Add(548253432, new COMMON::InputPeerChannel());
	AllObjects.Add(-1182234929, new COMMON::InputUserEmpty());
	AllObjects.Add(-138301121, new COMMON::InputUserSelf());
	AllObjects.Add(-668391402, new COMMON::InputUser());
	AllObjects.Add(-208488460, new COMMON::InputPhoneContact());
	AllObjects.Add(-181407105, new COMMON::InputFile());
	AllObjects.Add(-95482955, new COMMON::InputFileBig());
	AllObjects.Add(-1771768449, new COMMON::InputMediaEmpty());
	AllObjects.Add(792191537, new COMMON::InputMediaUploadedPhoto());
	AllObjects.Add(-2114308294, new COMMON::InputMediaPhoto());
	AllObjects.Add(-104578748, new COMMON::InputMediaGeoPoint());
	AllObjects.Add(-1494984313, new COMMON::InputMediaContact());
	AllObjects.Add(-476700163, new COMMON::InputMediaUploadedDocument());
	AllObjects.Add(1523279502, new COMMON::InputMediaDocument());
	AllObjects.Add(673687578, new COMMON::InputMediaVenue());
	AllObjects.Add(1212395773, new COMMON::InputMediaGifExternal());
	AllObjects.Add(-1609667052, new COMMON::InputMediaPhotoExternal());
	AllObjects.Add(-1225309387, new COMMON::InputMediaDocumentExternal());
	AllObjects.Add(-750828557, new COMMON::InputMediaGame());
	AllObjects.Add(-1844103547, new COMMON::InputMediaInvoice());
	AllObjects.Add(480546647, new COMMON::InputChatPhotoEmpty());
	AllObjects.Add(-1837345356, new COMMON::InputChatUploadedPhoto());
	AllObjects.Add(-1991004873, new COMMON::InputChatPhoto());
	AllObjects.Add(-457104426, new COMMON::InputGeoPointEmpty());
	AllObjects.Add(-206066487, new COMMON::InputGeoPoint());
	AllObjects.Add(483901197, new COMMON::InputPhotoEmpty());
	AllObjects.Add(-74070332, new COMMON::InputPhoto());
	AllObjects.Add(342061462, new COMMON::InputFileLocation());
	AllObjects.Add(-182231723, new COMMON::InputEncryptedFileLocation());
	AllObjects.Add(1125058340, new COMMON::InputDocumentFileLocation());
	AllObjects.Add(1996904104, new COMMON::InputAppEvent());
	AllObjects.Add(-1649296275, new COMMON::PeerUser());
	AllObjects.Add(-1160714821, new COMMON::PeerChat());
	AllObjects.Add(-1109531342, new COMMON::PeerChannel());
	AllObjects.Add(-1432995067, new STORAGE::FileUnknown());
	AllObjects.Add(1086091090, new STORAGE::FilePartial());
	AllObjects.Add(2130578964, new STORAGE::FileJpeg());
	AllObjects.Add(-891180321, new STORAGE::FileGif());
	AllObjects.Add(-1609667052, new STORAGE::FilePng());
	AllObjects.Add(-1373745011, new STORAGE::FilePdf());
	AllObjects.Add(1384777335, new STORAGE::FileMp3());
	AllObjects.Add(1258941372, new STORAGE::FileMov());
	AllObjects.Add(-1278304028, new STORAGE::FileMp4());
	AllObjects.Add(276907596, new STORAGE::FileWebp());
	AllObjects.Add(2086234950, new COMMON::FileLocationUnavailable());
	AllObjects.Add(1406570614, new COMMON::FileLocation());
	AllObjects.Add(537022650, new COMMON::UserEmpty());
	AllObjects.Add(773059779, new COMMON::User());
	AllObjects.Add(1326562017, new COMMON::UserProfilePhotoEmpty());
	AllObjects.Add(-715532088, new COMMON::UserProfilePhoto());
	AllObjects.Add(-1609667052, new COMMON::UserStatusEmpty());
	AllObjects.Add(-306628279, new COMMON::UserStatusOnline());
	AllObjects.Add(-1938800876, new COMMON::UserStatusOffline());
	AllObjects.Add(-496024847, new COMMON::UserStatusRecently());
	AllObjects.Add(-1609667052, new COMMON::UserStatusLastWeek());
	AllObjects.Add(2011940674, new COMMON::UserStatusLastMonth());
	AllObjects.Add(-1683826688, new COMMON::ChatEmpty());
	AllObjects.Add(-652419756, new COMMON::Chat());
	AllObjects.Add(-1609667052, new COMMON::ChatForbidden());
	AllObjects.Add(-1609667052, new COMMON::Channel());
	AllObjects.Add(681420594, new COMMON::ChannelForbidden());
	AllObjects.Add(771925524, new COMMON::ChatFull());
	AllObjects.Add(401891279, new COMMON::ChannelFull());
	AllObjects.Add(-925415106, new COMMON::ChatParticipant());
	AllObjects.Add(-636267638, new COMMON::ChatParticipantCreator());
	AllObjects.Add(-489233354, new COMMON::ChatParticipantAdmin());
	AllObjects.Add(-57668565, new COMMON::ChatParticipantsForbidden());
	AllObjects.Add(1061556205, new COMMON::ChatParticipants());
	AllObjects.Add(935395612, new COMMON::ChatPhotoEmpty());
	AllObjects.Add(1632839530, new COMMON::ChatPhoto());
	AllObjects.Add(-2082087340, new COMMON::MessageEmpty());
	AllObjects.Add(-1864508399, new COMMON::Message());
	AllObjects.Add(-1642487306, new COMMON::MessageService());
	AllObjects.Add(1038967584, new COMMON::MessageMediaEmpty());
	AllObjects.Add(-1256047857, new COMMON::MessageMediaPhoto());
	AllObjects.Add(1457575028, new COMMON::MessageMediaGeo());
	AllObjects.Add(1585262393, new COMMON::MessageMediaContact());
	AllObjects.Add(-1618676578, new COMMON::MessageMediaUnsupported());
	AllObjects.Add(2084836563, new COMMON::MessageMediaDocument());
	AllObjects.Add(-1557277184, new COMMON::MessageMediaWebPage());
	AllObjects.Add(2031269663, new COMMON::MessageMediaVenue());
	AllObjects.Add(-38694904, new COMMON::MessageMediaGame());
	AllObjects.Add(-2074799289, new COMMON::MessageMediaInvoice());
	AllObjects.Add(-1230047312, new COMMON::MessageActionEmpty());
	AllObjects.Add(-1503425638, new COMMON::MessageActionChatCreate());
	AllObjects.Add(-1247687078, new COMMON::MessageActionChatEditTitle());
	AllObjects.Add(2144015272, new COMMON::MessageActionChatEditPhoto());
	AllObjects.Add(-1780220945, new COMMON::MessageActionChatDeletePhoto());
	AllObjects.Add(1217033015, new COMMON::MessageActionChatAddUser());
	AllObjects.Add(-1297179892, new COMMON::MessageActionChatDeleteUser());
	AllObjects.Add(-123931160, new COMMON::MessageActionChatJoinedByLink());
	AllObjects.Add(-1781355374, new COMMON::MessageActionChannelCreate());
	AllObjects.Add(1371385889, new COMMON::MessageActionChatMigrateTo());
	AllObjects.Add(-1336546578, new COMMON::MessageActionChannelMigrateFrom());
	AllObjects.Add(-1799538451, new COMMON::MessageActionPinMessage());
	AllObjects.Add(-1615153660, new COMMON::MessageActionHistoryClear());
	AllObjects.Add(-1834538890, new COMMON::MessageActionGameScore());
	AllObjects.Add(-1892568281, new COMMON::MessageActionPaymentSentMe());
	AllObjects.Add(1080663248, new COMMON::MessageActionPaymentSent());
	AllObjects.Add(-2132731265, new COMMON::MessageActionPhoneCall());
	AllObjects.Add(1200788123, new COMMON::MessageActionScreenshotTaken());
	AllObjects.Add(-455150117, new COMMON::Dialog());
	AllObjects.Add(590459437, new COMMON::PhotoEmpty());
	AllObjects.Add(-1836524247, new COMMON::Photo());
	AllObjects.Add(-1609667052, new COMMON::PhotoSizeEmpty());
	AllObjects.Add(2009052699, new COMMON::PhotoSize());
	AllObjects.Add(-374917894, new COMMON::PhotoCachedSize());
	AllObjects.Add(286776671, new COMMON::GeoPointEmpty());
	AllObjects.Add(541710092, new COMMON::GeoPoint());
	AllObjects.Add(-2128698738, new AUTH::CheckedPhone());
	AllObjects.Add(1577067778, new AUTH::SentCode());
	AllObjects.Add(-855308010, new AUTH::Authorization());
	AllObjects.Add(-543777747, new AUTH::ExportedAuthorization());
	AllObjects.Add(-1195615476, new COMMON::InputNotifyPeer());
	AllObjects.Add(423314455, new COMMON::InputNotifyUsers());
	AllObjects.Add(1251338318, new COMMON::InputNotifyChats());
	AllObjects.Add(-1540769658, new COMMON::InputNotifyAll());
	AllObjects.Add(-265263912, new COMMON::InputPeerNotifyEventsEmpty());
	AllObjects.Add(-395694988, new COMMON::InputPeerNotifyEventsAll());
	AllObjects.Add(949182130, new COMMON::InputPeerNotifySettings());
	AllObjects.Add(-1378534221, new COMMON::PeerNotifyEventsEmpty());
	AllObjects.Add(1830677896, new COMMON::PeerNotifyEventsAll());
	AllObjects.Add(1889961234, new COMMON::PeerNotifySettingsEmpty());
	AllObjects.Add(-1697798976, new COMMON::PeerNotifySettings());
	AllObjects.Add(-2122045747, new COMMON::PeerSettings());
	AllObjects.Add(-860866985, new COMMON::WallPaper());
	AllObjects.Add(1662091044, new COMMON::WallPaperSolid());
	AllObjects.Add(1490799288, new COMMON::InputReportReasonSpam());
	AllObjects.Add(505595789, new COMMON::InputReportReasonViolence());
	AllObjects.Add(777640226, new COMMON::InputReportReasonPornography());
	AllObjects.Add(-512463606, new COMMON::InputReportReasonOther());
	AllObjects.Add(-1609667052, new COMMON::UserFull());
	AllObjects.Add(-116274796, new COMMON::Contact());
	AllObjects.Add(-805141448, new COMMON::ImportedContact());
	AllObjects.Add(1444661369, new COMMON::ContactBlocked());
	AllObjects.Add(-748155807, new COMMON::ContactStatus());
	AllObjects.Add(986597452, new CONTACTS::Link());
	AllObjects.Add(-1219778094, new CONTACTS::ContactsNotModified());
	AllObjects.Add(-353862078, new CONTACTS::Contacts());
	AllObjects.Add(2010127419, new CONTACTS::ImportedContacts());
	AllObjects.Add(471043349, new CONTACTS::Blocked());
	AllObjects.Add(-1878523231, new CONTACTS::BlockedSlice());
	AllObjects.Add(364538944, new MESSAGES::Dialogs());
	AllObjects.Add(1910543603, new MESSAGES::DialogsSlice());
	AllObjects.Add(-1938715001, new MESSAGES::Messages());
	AllObjects.Add(-1609667052, new MESSAGES::MessagesSlice());
	AllObjects.Add(-1725551049, new MESSAGES::ChannelMessages());
	AllObjects.Add(1694474197, new MESSAGES::Chats());
	AllObjects.Add(-1663561404, new MESSAGES::ChatsSlice());
	AllObjects.Add(-438840932, new MESSAGES::ChatFull());
	AllObjects.Add(-1269012015, new MESSAGES::AffectedHistory());
	AllObjects.Add(1474492012, new COMMON::InputMessagesFilterEmpty());
	AllObjects.Add(-1777752804, new COMMON::InputMessagesFilterPhotos());
	AllObjects.Add(-1614803355, new COMMON::InputMessagesFilterVideo());
	AllObjects.Add(1458172132, new COMMON::InputMessagesFilterPhotoVideo());
	AllObjects.Add(-648121413, new COMMON::InputMessagesFilterPhotoVideoDocuments());
	AllObjects.Add(-1629621880, new COMMON::InputMessagesFilterDocument());
	AllObjects.Add(2129714567, new COMMON::InputMessagesFilterUrl());
	AllObjects.Add(-3644025, new COMMON::InputMessagesFilterGif());
	AllObjects.Add(1358283666, new COMMON::InputMessagesFilterVoice());
	AllObjects.Add(928101534, new COMMON::InputMessagesFilterMusic());
	AllObjects.Add(975236280, new COMMON::InputMessagesFilterChatPhotos());
	AllObjects.Add(-2134272152, new COMMON::InputMessagesFilterPhoneCalls());
	AllObjects.Add(2054952868, new COMMON::InputMessagesFilterRoundVoice());
	AllObjects.Add(-1253451181, new COMMON::InputMessagesFilterRoundVideo());
	AllObjects.Add(-1040652646, new COMMON::InputMessagesFilterMyMentions());
	AllObjects.Add(522914557, new COMMON::UpdateNewMessage());
	AllObjects.Add(1318109142, new COMMON::UpdateMessageID());
	AllObjects.Add(-1576161051, new COMMON::UpdateDeleteMessages());
	AllObjects.Add(1548249383, new COMMON::UpdateUserTyping());
	AllObjects.Add(-1704596961, new COMMON::UpdateChatUserTyping());
	AllObjects.Add(-1609667052, new COMMON::UpdateChatParticipants());
	AllObjects.Add(469489699, new COMMON::UpdateUserStatus());
	AllObjects.Add(-1489818765, new COMMON::UpdateUserName());
	AllObjects.Add(-1791935732, new COMMON::UpdateUserPhoto());
	AllObjects.Add(628472761, new COMMON::UpdateContactRegistered());
	AllObjects.Add(-1657903163, new COMMON::UpdateContactLink());
	AllObjects.Add(314359194, new COMMON::UpdateNewEncryptedMessage());
	AllObjects.Add(386986326, new COMMON::UpdateEncryptedChatTyping());
	AllObjects.Add(-1264392051, new COMMON::UpdateEncryption());
	AllObjects.Add(956179895, new COMMON::UpdateEncryptedMessagesRead());
	AllObjects.Add(-364179876, new COMMON::UpdateChatParticipantAdd());
	AllObjects.Add(1851755554, new COMMON::UpdateChatParticipantDelete());
	AllObjects.Add(-1906403213, new COMMON::UpdateDcOptions());
	AllObjects.Add(-2131957734, new COMMON::UpdateUserBlocked());
	AllObjects.Add(-1094555409, new COMMON::UpdateNotifySettings());
	AllObjects.Add(-337352679, new COMMON::UpdateServiceNotification());
	AllObjects.Add(-298113238, new COMMON::UpdatePrivacy());
	AllObjects.Add(314130811, new COMMON::UpdateUserPhone());
	AllObjects.Add(-1721631396, new COMMON::UpdateReadHistoryInbox());
	AllObjects.Add(791617983, new COMMON::UpdateReadHistoryOutbox());
	AllObjects.Add(2139689491, new COMMON::UpdateWebPage());
	AllObjects.Add(1757493555, new COMMON::UpdateReadMessagesContents());
	AllObjects.Add(-352032773, new COMMON::UpdateChannelTooLong());
	AllObjects.Add(-1227598250, new COMMON::UpdateChannel());
	AllObjects.Add(1656358105, new COMMON::UpdateNewChannelMessage());
	AllObjects.Add(1108669311, new COMMON::UpdateReadChannelInbox());
	AllObjects.Add(-1015733815, new COMMON::UpdateDeleteChannelMessages());
	AllObjects.Add(-1734268085, new COMMON::UpdateChannelMessageViews());
	AllObjects.Add(1855224129, new COMMON::UpdateChatAdmins());
	AllObjects.Add(-1232070311, new COMMON::UpdateChatParticipantAdmin());
	AllObjects.Add(1753886890, new COMMON::UpdateNewStickerSet());
	AllObjects.Add(-1609667052, new COMMON::UpdateStickerSetsOrder());
	AllObjects.Add(1135492588, new COMMON::UpdateStickerSets());
	AllObjects.Add(-1821035490, new COMMON::UpdateSavedGifs());
	AllObjects.Add(1417832080, new COMMON::UpdateBotInlineQuery());
	AllObjects.Add(-1609667052, new COMMON::UpdateBotInlineSend());
	AllObjects.Add(457133559, new COMMON::UpdateEditChannelMessage());
	AllObjects.Add(-1738988427, new COMMON::UpdateChannelPinnedMessage());
	AllObjects.Add(-415938591, new COMMON::UpdateBotCallbackQuery());
	AllObjects.Add(-469536605, new COMMON::UpdateEditMessage());
	AllObjects.Add(-103646630, new COMMON::UpdateInlineBotCallbackQuery());
	AllObjects.Add(634833351, new COMMON::UpdateReadChannelOutbox());
	AllObjects.Add(-299124375, new COMMON::UpdateDraftMessage());
	AllObjects.Add(1461528386, new COMMON::UpdateReadFeaturedStickers());
	AllObjects.Add(-1706939360, new COMMON::UpdateRecentStickers());
	AllObjects.Add(-1574314746, new COMMON::UpdateConfig());
	AllObjects.Add(861169551, new COMMON::UpdatePtsChanged());
	AllObjects.Add(1081547008, new COMMON::UpdateChannelWebPage());
	AllObjects.Add(-686710068, new COMMON::UpdateDialogPinned());
	AllObjects.Add(-657787251, new COMMON::UpdatePinnedDialogs());
	AllObjects.Add(-2095595325, new COMMON::UpdateBotWebhookJSON());
	AllObjects.Add(-1684914010, new COMMON::UpdateBotWebhookJSONQuery());
	AllObjects.Add(-523384512, new COMMON::UpdateBotShippingQuery());
	AllObjects.Add(1563376297, new COMMON::UpdateBotPrecheckoutQuery());
	AllObjects.Add(-1425052898, new COMMON::UpdatePhoneCall());
	AllObjects.Add(281165899, new COMMON::UpdateLangPackTooLong());
	AllObjects.Add(1442983757, new COMMON::UpdateLangPack());
	AllObjects.Add(-451831443, new COMMON::UpdateFavedStickers());
	AllObjects.Add(-1987495099, new COMMON::UpdateChannelReadMessagesContents());
	AllObjects.Add(1887741886, new COMMON::UpdateContactsReset());
	AllObjects.Add(-1519637954, new UPDATES::State());
	AllObjects.Add(1567990072, new UPDATES::DifferenceEmpty());
	AllObjects.Add(-191061996, new UPDATES::Difference());
	AllObjects.Add(-1459938943, new UPDATES::DifferenceSlice());
	AllObjects.Add(1258196845, new UPDATES::DifferenceTooLong());
	AllObjects.Add(-484987010, new COMMON::UpdatesTooLong());
	AllObjects.Add(-1857044719, new COMMON::UpdateShortMessage());
	AllObjects.Add(377562760, new COMMON::UpdateShortChatMessage());
	AllObjects.Add(2027216577, new COMMON::UpdateShort());
	AllObjects.Add(1918567619, new COMMON::UpdatesCombined());
	AllObjects.Add(1957577280, new COMMON::Updates());
	AllObjects.Add(301019932, new COMMON::UpdateShortSentMessage());
	AllObjects.Add(-1916114267, new PHOTOS::Photos());
	AllObjects.Add(352657236, new PHOTOS::PhotosSlice());
	AllObjects.Add(539045032, new PHOTOS::Photo());
	AllObjects.Add(-1609667052, new UPLOAD::File());
	AllObjects.Add(-363659686, new UPLOAD::FileCdnRedirect());
	AllObjects.Add(-1609667052, new COMMON::DcOption());
	AllObjects.Add(-1913424220, new COMMON::Config());
	AllObjects.Add(-1910892683, new COMMON::NearestDc());
	AllObjects.Add(-1987579119, new HELP::AppUpdate());
	AllObjects.Add(-1000708810, new HELP::NoAppUpdate());
	AllObjects.Add(415997816, new HELP::InviteText());
	AllObjects.Add(-1417756512, new COMMON::EncryptedChatEmpty());
	AllObjects.Add(1006044124, new COMMON::EncryptedChatWaiting());
	AllObjects.Add(-931638658, new COMMON::EncryptedChatRequested());
	AllObjects.Add(-94974410, new COMMON::EncryptedChat());
	AllObjects.Add(332848423, new COMMON::EncryptedChatDiscarded());
	AllObjects.Add(-247351839, new COMMON::InputEncryptedChat());
	AllObjects.Add(-1038136962, new COMMON::EncryptedFileEmpty());
	AllObjects.Add(1248893260, new COMMON::EncryptedFile());
	AllObjects.Add(406307684, new COMMON::InputEncryptedFileEmpty());
	AllObjects.Add(1690108678, new COMMON::InputEncryptedFileUploaded());
	AllObjects.Add(1511503333, new COMMON::InputEncryptedFile());
	AllObjects.Add(767652808, new COMMON::InputEncryptedFileBigUploaded());
	AllObjects.Add(-317144808, new COMMON::EncryptedMessage());
	AllObjects.Add(594758406, new COMMON::EncryptedMessageService());
	AllObjects.Add(-1058912715, new MESSAGES::DhConfigNotModified());
	AllObjects.Add(740433629, new MESSAGES::DhConfig());
	AllObjects.Add(1443858741, new MESSAGES::SentEncryptedMessage());
	AllObjects.Add(-1802240206, new MESSAGES::SentEncryptedFile());
	AllObjects.Add(1928391342, new COMMON::InputDocumentEmpty());
	AllObjects.Add(410618194, new COMMON::InputDocument());
	AllObjects.Add(922273905, new COMMON::DocumentEmpty());
	AllObjects.Add(-2027738169, new COMMON::Document());
	AllObjects.Add(398898678, new HELP::Support());
	AllObjects.Add(-1613493288, new COMMON::NotifyPeer());
	AllObjects.Add(-1261946036, new COMMON::NotifyUsers());
	AllObjects.Add(-1073230141, new COMMON::NotifyChats());
	AllObjects.Add(1959820384, new COMMON::NotifyAll());
	AllObjects.Add(381645902, new COMMON::SendMessageTypingAction());
	AllObjects.Add(-44119819, new COMMON::SendMessageCancelAction());
	AllObjects.Add(-1584933265, new COMMON::SendMessageRecordVideoAction());
	AllObjects.Add(-378127636, new COMMON::SendMessageUploadVideoAction());
	AllObjects.Add(-718310409, new COMMON::SendMessageRecordAudioAction());
	AllObjects.Add(-212740181, new COMMON::SendMessageUploadAudioAction());
	AllObjects.Add(-774682074, new COMMON::SendMessageUploadPhotoAction());
	AllObjects.Add(-1441998364, new COMMON::SendMessageUploadDocumentAction());
	AllObjects.Add(393186209, new COMMON::SendMessageGeoLocationAction());
	AllObjects.Add(1653390447, new COMMON::SendMessageChooseContactAction());
	AllObjects.Add(-580219064, new COMMON::SendMessageGamePlayAction());
	AllObjects.Add(-1997373508, new COMMON::SendMessageRecordRoundAction());
	AllObjects.Add(608050278, new COMMON::SendMessageUploadRoundAction());
	AllObjects.Add(446822276, new CONTACTS::Found());
	AllObjects.Add(1335282456, new COMMON::InputPrivacyKeyStatusTimestamp());
	AllObjects.Add(-1107622874, new COMMON::InputPrivacyKeyChatInvite());
	AllObjects.Add(-88417185, new COMMON::InputPrivacyKeyPhoneCall());
	AllObjects.Add(-1137792208, new COMMON::PrivacyKeyStatusTimestamp());
	AllObjects.Add(1343122938, new COMMON::PrivacyKeyChatInvite());
	AllObjects.Add(1030105979, new COMMON::PrivacyKeyPhoneCall());
	AllObjects.Add(-1609667052, new COMMON::InputPrivacyValueAllowContacts());
	AllObjects.Add(407582158, new COMMON::InputPrivacyValueAllowAll());
	AllObjects.Add(320652927, new COMMON::InputPrivacyValueAllowUsers());
	AllObjects.Add(-1609667052, new COMMON::InputPrivacyValueDisallowContacts());
	AllObjects.Add(-697604407, new COMMON::InputPrivacyValueDisallowAll());
	AllObjects.Add(-1877932953, new COMMON::InputPrivacyValueDisallowUsers());
	AllObjects.Add(-123988, new COMMON::PrivacyValueAllowContacts());
	AllObjects.Add(1698855810, new COMMON::PrivacyValueAllowAll());
	AllObjects.Add(1297858060, new COMMON::PrivacyValueAllowUsers());
	AllObjects.Add(-125240806, new COMMON::PrivacyValueDisallowContacts());
	AllObjects.Add(-1955338397, new COMMON::PrivacyValueDisallowAll());
	AllObjects.Add(-1609667052, new COMMON::PrivacyValueDisallowUsers());
	AllObjects.Add(1430961007, new ACCOUNT::PrivacyRules());
	AllObjects.Add(-1194283041, new COMMON::AccountDaysTTL());
	AllObjects.Add(1815593308, new COMMON::DocumentAttributeImageSize());
	AllObjects.Add(297109817, new COMMON::DocumentAttributeAnimated());
	AllObjects.Add(1662637586, new COMMON::DocumentAttributeSticker());
	AllObjects.Add(-1609667052, new COMMON::DocumentAttributeVideo());
	AllObjects.Add(-1739392570, new COMMON::DocumentAttributeAudio());
	AllObjects.Add(358154344, new COMMON::DocumentAttributeFilename());
	AllObjects.Add(-1744710921, new COMMON::DocumentAttributeHasStickers());
	AllObjects.Add(-244016606, new MESSAGES::StickersNotModified());
	AllObjects.Add(-1970352846, new MESSAGES::Stickers());
	AllObjects.Add(313694676, new COMMON::StickerPack());
	AllObjects.Add(-395967805, new MESSAGES::AllStickersNotModified());
	AllObjects.Add(-302170017, new MESSAGES::AllStickers());
	AllObjects.Add(-1369215196, new COMMON::DisabledFeature());
	AllObjects.Add(-2066640507, new MESSAGES::AffectedMessages());
	AllObjects.Add(1599050311, new COMMON::ContactLinkUnknown());
	AllObjects.Add(-17968211, new COMMON::ContactLinkNone());
	AllObjects.Add(646922073, new COMMON::ContactLinkHasPhone());
	AllObjects.Add(-721239344, new COMMON::ContactLinkContact());
	AllObjects.Add(-350980120, new COMMON::WebPageEmpty());
	AllObjects.Add(-981018084, new COMMON::WebPagePending());
	AllObjects.Add(1594340540, new COMMON::WebPage());
	AllObjects.Add(-2054908813, new COMMON::WebPageNotModified());
	AllObjects.Add(2079516406, new COMMON::Authorization());
	AllObjects.Add(307276766, new ACCOUNT::Authorizations());
	AllObjects.Add(-1764049896, new ACCOUNT::NoPassword());
	AllObjects.Add(2081952796, new ACCOUNT::Password());
	AllObjects.Add(-1212732749, new ACCOUNT::PasswordSettings());
	AllObjects.Add(-2037289493, new ACCOUNT::PasswordInputSettings());
	AllObjects.Add(326715557, new AUTH::PasswordRecovery());
	AllObjects.Add(-1551583367, new COMMON::ReceivedNotifyMessage());
	AllObjects.Add(1776236393, new COMMON::ChatInviteEmpty());
	AllObjects.Add(-64092740, new COMMON::ChatInviteExported());
	AllObjects.Add(1516793212, new COMMON::ChatInviteAlready());
	AllObjects.Add(-613092008, new COMMON::ChatInvite());
	AllObjects.Add(-4838507, new COMMON::InputStickerSetEmpty());
	AllObjects.Add(-1645763991, new COMMON::InputStickerSetID());
	AllObjects.Add(-2044933984, new COMMON::InputStickerSetShortName());
	AllObjects.Add(-852477119, new COMMON::StickerSet());
	AllObjects.Add(-1240849242, new MESSAGES::StickerSet());
	AllObjects.Add(-1032140601, new COMMON::BotCommand());
	AllObjects.Add(-1729618630, new COMMON::BotInfo());
	AllObjects.Add(-1560655744, new COMMON::KeyboardButton());
	AllObjects.Add(629866245, new COMMON::KeyboardButtonUrl());
	AllObjects.Add(1748655686, new COMMON::KeyboardButtonCallback());
	AllObjects.Add(-1318425559, new COMMON::KeyboardButtonRequestPhone());
	AllObjects.Add(-59151553, new COMMON::KeyboardButtonRequestGeoLocation());
	AllObjects.Add(-1609667052, new COMMON::KeyboardButtonSwitchInline());
	AllObjects.Add(1358175439, new COMMON::KeyboardButtonGame());
	AllObjects.Add(-1344716869, new COMMON::KeyboardButtonBuy());
	AllObjects.Add(2002815875, new COMMON::KeyboardButtonRow());
	AllObjects.Add(-1606526075, new COMMON::ReplyKeyboardHide());
	AllObjects.Add(-200242528, new COMMON::ReplyKeyboardForceReply());
	AllObjects.Add(889353612, new COMMON::ReplyKeyboardMarkup());
	AllObjects.Add(1218642516, new COMMON::ReplyInlineMarkup());
	AllObjects.Add(-1148011883, new COMMON::MessageEntityUnknown());
	AllObjects.Add(-100378723, new COMMON::MessageEntityMention());
	AllObjects.Add(1868782349, new COMMON::MessageEntityHashtag());
	AllObjects.Add(1827637959, new COMMON::MessageEntityBotCommand());
	AllObjects.Add(1859134776, new COMMON::MessageEntityUrl());
	AllObjects.Add(1692693954, new COMMON::MessageEntityEmail());
	AllObjects.Add(-1117713463, new COMMON::MessageEntityBold());
	AllObjects.Add(-2106619040, new COMMON::MessageEntityItalic());
	AllObjects.Add(681706865, new COMMON::MessageEntityCode());
	AllObjects.Add(1938967520, new COMMON::MessageEntityPre());
	AllObjects.Add(1990644519, new COMMON::MessageEntityTextUrl());
	AllObjects.Add(892193368, new COMMON::MessageEntityMentionName());
	AllObjects.Add(546203849, new COMMON::InputMessageEntityMentionName());
	AllObjects.Add(-292807034, new COMMON::InputChannelEmpty());
	AllObjects.Add(-1343524562, new COMMON::InputChannel());
	AllObjects.Add(2131196633, new CONTACTS::ResolvedPeer());
	AllObjects.Add(-1609667052, new COMMON::MessageRange());
	AllObjects.Add(1041346555, new UPDATES::ChannelDifferenceEmpty());
	AllObjects.Add(1788705589, new UPDATES::ChannelDifferenceTooLong());
	AllObjects.Add(543450958, new UPDATES::ChannelDifference());
	AllObjects.Add(-1798033689, new COMMON::ChannelMessagesFilterEmpty());
	AllObjects.Add(-847783593, new COMMON::ChannelMessagesFilter());
	AllObjects.Add(367766557, new COMMON::ChannelParticipant());
	AllObjects.Add(-1557620115, new COMMON::ChannelParticipantSelf());
	AllObjects.Add(-471670279, new COMMON::ChannelParticipantCreator());
	AllObjects.Add(-1473271656, new COMMON::ChannelParticipantAdmin());
	AllObjects.Add(573315206, new COMMON::ChannelParticipantBanned());
	AllObjects.Add(-566281095, new COMMON::ChannelParticipantsRecent());
	AllObjects.Add(-1268741783, new COMMON::ChannelParticipantsAdmins());
	AllObjects.Add(-1548400251, new COMMON::ChannelParticipantsKicked());
	AllObjects.Add(-1328445861, new COMMON::ChannelParticipantsBots());
	AllObjects.Add(338142689, new COMMON::ChannelParticipantsBanned());
	AllObjects.Add(-1609667052, new COMMON::ChannelParticipantsSearch());
	AllObjects.Add(-177282392, new CHANNELS::ChannelParticipants());
	AllObjects.Add(-791039645, new CHANNELS::ChannelParticipant());
	AllObjects.Add(-236044656, new HELP::TermsOfService());
	AllObjects.Add(372165663, new COMMON::FoundGif());
	AllObjects.Add(-1670052855, new COMMON::FoundGifCached());
	AllObjects.Add(1158290442, new MESSAGES::FoundGifs());
	AllObjects.Add(-402498398, new MESSAGES::SavedGifsNotModified());
	AllObjects.Add(772213157, new MESSAGES::SavedGifs());
	AllObjects.Add(691006739, new COMMON::InputBotInlineMessageMediaAuto());
	AllObjects.Add(1036876423, new COMMON::InputBotInlineMessageText());
	AllObjects.Add(-190472735, new COMMON::InputBotInlineMessageMediaGeo());
	AllObjects.Add(-1431327288, new COMMON::InputBotInlineMessageMediaVenue());
	AllObjects.Add(766443943, new COMMON::InputBotInlineMessageMediaContact());
	AllObjects.Add(1262639204, new COMMON::InputBotInlineMessageGame());
	AllObjects.Add(750510426, new COMMON::InputBotInlineResult());
	AllObjects.Add(-1462213465, new COMMON::InputBotInlineResultPhoto());
	AllObjects.Add(-459324, new COMMON::InputBotInlineResultDocument());
	AllObjects.Add(1336154098, new COMMON::InputBotInlineResultGame());
	AllObjects.Add(-1609667052, new COMMON::BotInlineMessageMediaAuto());
	AllObjects.Add(-1937807902, new COMMON::BotInlineMessageText());
	AllObjects.Add(982505656, new COMMON::BotInlineMessageMediaGeo());
	AllObjects.Add(1130767150, new COMMON::BotInlineMessageMediaVenue());
	AllObjects.Add(904770772, new COMMON::BotInlineMessageMediaContact());
	AllObjects.Add(-1679053127, new COMMON::BotInlineResult());
	AllObjects.Add(400266251, new COMMON::BotInlineMediaResult());
	AllObjects.Add(-858565059, new MESSAGES::BotResults());
	AllObjects.Add(524838915, new COMMON::ExportedMessageLink());
	AllObjects.Add(-85986132, new COMMON::MessageFwdHeader());
	AllObjects.Add(1923290508, new AUTH::CodeTypeSms());
	AllObjects.Add(1948046307, new AUTH::CodeTypeCall());
	AllObjects.Add(577556219, new AUTH::CodeTypeFlashCall());
	AllObjects.Add(1035688326, new AUTH::SentCodeTypeApp());
	AllObjects.Add(-1073693790, new AUTH::SentCodeTypeSms());
	AllObjects.Add(1398007207, new AUTH::SentCodeTypeCall());
	AllObjects.Add(-1425815847, new AUTH::SentCodeTypeFlashCall());
	AllObjects.Add(911761060, new MESSAGES::BotCallbackAnswer());
	AllObjects.Add(649453030, new MESSAGES::MessageEditData());
	AllObjects.Add(-1995686519, new COMMON::InputBotInlineMessageID());
	AllObjects.Add(1008755359, new COMMON::InlineBotSwitchPM());
	AllObjects.Add(863093588, new MESSAGES::PeerDialogs());
	AllObjects.Add(-305282981, new COMMON::TopPeer());
	AllObjects.Add(-1419371685, new COMMON::TopPeerCategoryBotsPM());
	AllObjects.Add(344356834, new COMMON::TopPeerCategoryBotsInline());
	AllObjects.Add(-1609667052, new COMMON::TopPeerCategoryCorrespondents());
	AllObjects.Add(-1122524854, new COMMON::TopPeerCategoryGroups());
	AllObjects.Add(371037736, new COMMON::TopPeerCategoryChannels());
	AllObjects.Add(511092620, new COMMON::TopPeerCategoryPhoneCalls());
	AllObjects.Add(-75283823, new COMMON::TopPeerCategoryPeers());
	AllObjects.Add(-567906571, new CONTACTS::TopPeersNotModified());
	AllObjects.Add(1891070632, new CONTACTS::TopPeers());
	AllObjects.Add(-1169445179, new COMMON::DraftMessageEmpty());
	AllObjects.Add(-40996577, new COMMON::DraftMessage());
	AllObjects.Add(-1609667052, new MESSAGES::FeaturedStickersNotModified());
	AllObjects.Add(-123893531, new MESSAGES::FeaturedStickers());
	AllObjects.Add(-1609667052, new MESSAGES::RecentStickersNotModified());
	AllObjects.Add(1558317424, new MESSAGES::RecentStickers());
	AllObjects.Add(1338747336, new MESSAGES::ArchivedStickers());
	AllObjects.Add(946083368, new MESSAGES::StickerSetInstallResultSuccess());
	AllObjects.Add(904138920, new MESSAGES::StickerSetInstallResultArchive());
	AllObjects.Add(1678812626, new COMMON::StickerSetCovered());
	AllObjects.Add(872932635, new COMMON::StickerSetMultiCovered());
	AllObjects.Add(-1361650766, new COMMON::MaskCoords());
	AllObjects.Add(1251549527, new COMMON::InputStickeredMediaPhoto());
	AllObjects.Add(-1609667052, new COMMON::InputStickeredMediaDocument());
	AllObjects.Add(-1107729093, new COMMON::Game());
	AllObjects.Add(-1609667052, new COMMON::InputGameID());
	AllObjects.Add(-1020139510, new COMMON::InputGameShortName());
	AllObjects.Add(1493171408, new COMMON::HighScore());
	AllObjects.Add(-1707344487, new MESSAGES::HighScores());
	AllObjects.Add(-599948721, new COMMON::TextEmpty());
	AllObjects.Add(1950782688, new COMMON::TextPlain());
	AllObjects.Add(1730456516, new COMMON::TextBold());
	AllObjects.Add(-653089380, new COMMON::TextItalic());
	AllObjects.Add(-1054465340, new COMMON::TextUnderline());
	AllObjects.Add(-1678197867, new COMMON::TextStrike());
	AllObjects.Add(1816074681, new COMMON::TextFixed());
	AllObjects.Add(1009288385, new COMMON::TextUrl());
	AllObjects.Add(-564523562, new COMMON::TextEmail());
	AllObjects.Add(2120376535, new COMMON::TextConcat());
	AllObjects.Add(324435594, new COMMON::PageBlockUnsupported());
	AllObjects.Add(1890305021, new COMMON::PageBlockTitle());
	AllObjects.Add(-1879401953, new COMMON::PageBlockSubtitle());
	AllObjects.Add(-1162877472, new COMMON::PageBlockAuthorDate());
	AllObjects.Add(-1076861716, new COMMON::PageBlockHeader());
	AllObjects.Add(-248793375, new COMMON::PageBlockSubheader());
	AllObjects.Add(1182402406, new COMMON::PageBlockParagraph());
	AllObjects.Add(-1066346178, new COMMON::PageBlockPreformatted());
	AllObjects.Add(1216809369, new COMMON::PageBlockFooter());
	AllObjects.Add(-618614392, new COMMON::PageBlockDivider());
	AllObjects.Add(-837994576, new COMMON::PageBlockAnchor());
	AllObjects.Add(978896884, new COMMON::PageBlockList());
	AllObjects.Add(641563686, new COMMON::PageBlockBlockquote());
	AllObjects.Add(1329878739, new COMMON::PageBlockPullquote());
	AllObjects.Add(-372860542, new COMMON::PageBlockPhoto());
	AllObjects.Add(-640214938, new COMMON::PageBlockVideo());
	AllObjects.Add(972174080, new COMMON::PageBlockCover());
	AllObjects.Add(-840826671, new COMMON::PageBlockEmbed());
	AllObjects.Add(690781161, new COMMON::PageBlockEmbedPost());
	AllObjects.Add(-1609667052, new COMMON::PageBlockCollage());
	AllObjects.Add(319588707, new COMMON::PageBlockSlideshow());
	AllObjects.Add(-283684427, new COMMON::PageBlockChannel());
	AllObjects.Add(834148991, new COMMON::PageBlockAudio());
	AllObjects.Add(-1908433218, new COMMON::PagePart());
	AllObjects.Add(1433323434, new COMMON::PageFull());
	AllObjects.Add(-2048646399, new COMMON::PhoneCallDiscardReasonMissed());
	AllObjects.Add(-527056480, new COMMON::PhoneCallDiscardReasonDisconnect());
	AllObjects.Add(1471006352, new COMMON::PhoneCallDiscardReasonHangup());
	AllObjects.Add(-84416311, new COMMON::PhoneCallDiscardReasonBusy());
	AllObjects.Add(2104790276, new COMMON::DataJSON());
	AllObjects.Add(-886477832, new COMMON::LabeledPrice());
	AllObjects.Add(-1022713000, new COMMON::Invoice());
	AllObjects.Add(-368917890, new COMMON::PaymentCharge());
	AllObjects.Add(512535275, new COMMON::PostAddress());
	AllObjects.Add(-1868808300, new COMMON::PaymentRequestedInfo());
	AllObjects.Add(-842892769, new COMMON::PaymentSavedCredentialsCard());
	AllObjects.Add(-971322408, new COMMON::WebDocument());
	AllObjects.Add(-1678949555, new COMMON::InputWebDocument());
	AllObjects.Add(-1036396922, new COMMON::InputWebFileLocation());
	AllObjects.Add(568808380, new UPLOAD::WebFile());
	AllObjects.Add(1062645411, new PAYMENTS::PaymentForm());
	AllObjects.Add(-784000893, new PAYMENTS::ValidatedRequestedInfo());
	AllObjects.Add(1314881805, new PAYMENTS::PaymentResult());
	AllObjects.Add(1800845601, new PAYMENTS::PaymentVerficationNeeded());
	AllObjects.Add(1342771681, new PAYMENTS::PaymentReceipt());
	AllObjects.Add(-74456004, new PAYMENTS::SavedInfo());
	AllObjects.Add(-1056001329, new COMMON::InputPaymentCredentialsSaved());
	AllObjects.Add(873977640, new COMMON::InputPaymentCredentials());
	AllObjects.Add(-614138572, new ACCOUNT::TmpPassword());
	AllObjects.Add(-1239335713, new COMMON::ShippingOption());
	AllObjects.Add(-6249322, new COMMON::InputStickerSetItem());
	AllObjects.Add(506920429, new COMMON::InputPhoneCall());
	AllObjects.Add(1399245077, new COMMON::PhoneCallEmpty());
	AllObjects.Add(462375633, new COMMON::PhoneCallWaiting());
	AllObjects.Add(-2089411356, new COMMON::PhoneCallRequested());
	AllObjects.Add(1828732223, new COMMON::PhoneCallAccepted());
	AllObjects.Add(-1660057, new COMMON::PhoneCall());
	AllObjects.Add(1355435489, new COMMON::PhoneCallDiscarded());
	AllObjects.Add(-1655957568, new COMMON::PhoneConnection());
	AllObjects.Add(-1564789301, new COMMON::PhoneCallProtocol());
	AllObjects.Add(-326966976, new PHONE::PhoneCall());
	AllObjects.Add(-290921362, new UPLOAD::CdnFileReuploadNeeded());
	AllObjects.Add(-1449145777, new UPLOAD::CdnFile());
	AllObjects.Add(-914167110, new COMMON::CdnPublicKey());
	AllObjects.Add(1462101002, new COMMON::CdnConfig());
	AllObjects.Add(-892239370, new COMMON::LangPackString());
	AllObjects.Add(1816636575, new COMMON::LangPackStringPluralized());
	AllObjects.Add(695856818, new COMMON::LangPackStringDeleted());
	AllObjects.Add(-209337866, new COMMON::LangPackDifference());
	AllObjects.Add(292985073, new COMMON::LangPackLanguage());
	AllObjects.Add(1568467877, new COMMON::ChannelAdminRights());
	AllObjects.Add(1489977929, new COMMON::ChannelBannedRights());
	AllObjects.Add(-421545947, new COMMON::ChannelAdminLogEventActionChangeTitle());
	AllObjects.Add(1427671598, new COMMON::ChannelAdminLogEventActionChangeAbout());
	AllObjects.Add(1783299128, new COMMON::ChannelAdminLogEventActionChangeUsername());
	AllObjects.Add(-1204857405, new COMMON::ChannelAdminLogEventActionChangePhoto());
	AllObjects.Add(460916654, new COMMON::ChannelAdminLogEventActionToggleInvites());
	AllObjects.Add(648939889, new COMMON::ChannelAdminLogEventActionToggleSignatures());
	AllObjects.Add(-370660328, new COMMON::ChannelAdminLogEventActionUpdatePinned());
	AllObjects.Add(1889215493, new COMMON::ChannelAdminLogEventActionEditMessage());
	AllObjects.Add(1121994683, new COMMON::ChannelAdminLogEventActionDeleteMessage());
	AllObjects.Add(405815507, new COMMON::ChannelAdminLogEventActionParticipantJoin());
	AllObjects.Add(-124291086, new COMMON::ChannelAdminLogEventActionParticipantLeave());
	AllObjects.Add(-484690728, new COMMON::ChannelAdminLogEventActionParticipantInvite());
	AllObjects.Add(-422036098, new COMMON::ChannelAdminLogEventActionParticipantToggleBan());
	AllObjects.Add(-714643696, new COMMON::ChannelAdminLogEventActionParticipantToggleAdmin());
	AllObjects.Add(-1312568665, new COMMON::ChannelAdminLogEventActionChangeStickerSet());
	AllObjects.Add(995769920, new COMMON::ChannelAdminLogEvent());
	AllObjects.Add(-309659827, new CHANNELS::AdminLogResults());
	AllObjects.Add(-368018716, new COMMON::ChannelAdminLogEventsFilter());
	AllObjects.Add(1558266229, new COMMON::PopularContact());
	AllObjects.Add(2012136335, new COMMON::CdnFileHash());
	AllObjects.Add(-1634752813, new MESSAGES::FavedStickersNotModified());
	AllObjects.Add(-209768682, new MESSAGES::FavedStickers());
	AllObjects.Add(-878758099, new COMMON::InvokeAfterMsg());
	AllObjects.Add(1036301552, new COMMON::InvokeAfterMsgs());
	AllObjects.Add(-951575130, new COMMON::InitConnection());
	AllObjects.Add(-627372787, new COMMON::InvokeWithLayer());
	AllObjects.Add(-1080796745, new COMMON::InvokeWithoutUpdates());
	AllObjects.Add(1877286395, new AUTH::CheckPhone());
	AllObjects.Add(-2035355412, new AUTH::SendCode());
	AllObjects.Add(453408308, new AUTH::SignUp());
	AllObjects.Add(-1126886015, new AUTH::SignIn());
	AllObjects.Add(1461180992, new AUTH::LogOut());
	AllObjects.Add(-1616179942, new AUTH::ResetAuthorizations());
	AllObjects.Add(1998331287, new AUTH::SendInvites());
	AllObjects.Add(-440401971, new AUTH::ExportAuthorization());
	AllObjects.Add(-470837741, new AUTH::ImportAuthorization());
	AllObjects.Add(-841733627, new AUTH::BindTempAuthKey());
	AllObjects.Add(1738800940, new AUTH::ImportBotAuthorization());
	AllObjects.Add(-1609667052, new AUTH::CheckPassword());
	AllObjects.Add(-661144474, new AUTH::RequestPasswordRecovery());
	AllObjects.Add(1319464594, new AUTH::RecoverPassword());
	AllObjects.Add(1056025023, new AUTH::ResendCode());
	AllObjects.Add(520357240, new AUTH::CancelCode());
	AllObjects.Add(-1907842680, new AUTH::DropTempAuthKeys());
	AllObjects.Add(1669245048, new ACCOUNT::RegisterDevice());
	AllObjects.Add(1707432768, new ACCOUNT::UnregisterDevice());
	AllObjects.Add(-2067899501, new ACCOUNT::UpdateNotifySettings());
	AllObjects.Add(313765169, new ACCOUNT::GetNotifySettings());
	AllObjects.Add(-612493497, new ACCOUNT::ResetNotifySettings());
	AllObjects.Add(2018596725, new ACCOUNT::UpdateProfile());
	AllObjects.Add(1713919532, new ACCOUNT::UpdateStatus());
	AllObjects.Add(-1068696894, new ACCOUNT::GetWallPapers());
	AllObjects.Add(-1374118561, new ACCOUNT::ReportPeer());
	AllObjects.Add(655677548, new ACCOUNT::CheckUsername());
	AllObjects.Add(1040964988, new ACCOUNT::UpdateUsername());
	AllObjects.Add(-623130288, new ACCOUNT::GetPrivacy());
	AllObjects.Add(-906486552, new ACCOUNT::SetPrivacy());
	AllObjects.Add(1099779595, new ACCOUNT::DeleteAccount());
	AllObjects.Add(-1609667052, new ACCOUNT::GetAccountTTL());
	AllObjects.Add(608323678, new ACCOUNT::SetAccountTTL());
	AllObjects.Add(-1609667052, new ACCOUNT::SendChangePhoneCode());
	AllObjects.Add(1891839707, new ACCOUNT::ChangePhone());
	AllObjects.Add(954152242, new ACCOUNT::UpdateDeviceLocked());
	AllObjects.Add(-484392616, new ACCOUNT::GetAuthorizations());
	AllObjects.Add(-545786948, new ACCOUNT::ResetAuthorization());
	AllObjects.Add(1418342645, new ACCOUNT::GetPassword());
	AllObjects.Add(-1131605573, new ACCOUNT::GetPasswordSettings());
	AllObjects.Add(-92517498, new ACCOUNT::UpdatePasswordSettings());
	AllObjects.Add(353818557, new ACCOUNT::SendConfirmPhoneCode());
	AllObjects.Add(1596029123, new ACCOUNT::ConfirmPhone());
	AllObjects.Add(1250046590, new ACCOUNT::GetTmpPassword());
	AllObjects.Add(1751359642, new USERS::GetUsers());
	AllObjects.Add(-902781519, new USERS::GetFullUser());
	AllObjects.Add(-995929106, new CONTACTS::GetStatuses());
	AllObjects.Add(-1071414113, new CONTACTS::GetContacts());
	AllObjects.Add(746589157, new CONTACTS::ImportContacts());
	AllObjects.Add(-1902823612, new CONTACTS::DeleteContact());
	AllObjects.Add(1504393374, new CONTACTS::DeleteContacts());
	AllObjects.Add(858475004, new CONTACTS::Block());
	AllObjects.Add(-448724803, new CONTACTS::Unblock());
	AllObjects.Add(-176409329, new CONTACTS::GetBlocked());
	AllObjects.Add(-2065352905, new CONTACTS::ExportCard());
	AllObjects.Add(1340184318, new CONTACTS::ImportCard());
	AllObjects.Add(301470424, new CONTACTS::Search());
	AllObjects.Add(-113456221, new CONTACTS::ResolveUsername());
	AllObjects.Add(-728224331, new CONTACTS::GetTopPeers());
	AllObjects.Add(451113900, new CONTACTS::ResetTopPeerRating());
	AllObjects.Add(-2020263951, new CONTACTS::ResetSaved());
	AllObjects.Add(1109588596, new MESSAGES::GetMessages());
	AllObjects.Add(421243333, new MESSAGES::GetDialogs());
	AllObjects.Add(-1347868602, new MESSAGES::GetHistory());
	AllObjects.Add(-1609667052, new MESSAGES::Search());
	AllObjects.Add(-1609667052, new MESSAGES::ReadHistory());
	AllObjects.Add(469850889, new MESSAGES::DeleteHistory());
	AllObjects.Add(-443640366, new MESSAGES::DeleteMessages());
	AllObjects.Add(1751359642, new MESSAGES::ReceivedMessages());
	AllObjects.Add(-1551737264, new MESSAGES::SetTyping());
	AllObjects.Add(-91733382, new MESSAGES::SendMessage());
	AllObjects.Add(-923703407, new MESSAGES::SendMedia());
	AllObjects.Add(1888354709, new MESSAGES::ForwardMessages());
	AllObjects.Add(-820669733, new MESSAGES::ReportSpam());
	AllObjects.Add(-1460572005, new MESSAGES::HideReportSpam());
	AllObjects.Add(913498268, new MESSAGES::GetPeerSettings());
	AllObjects.Add(1013621127, new MESSAGES::GetChats());
	AllObjects.Add(998448230, new MESSAGES::GetFullChat());
	AllObjects.Add(-599447467, new MESSAGES::EditChatTitle());
	AllObjects.Add(-900957736, new MESSAGES::EditChatPhoto());
	AllObjects.Add(-106911223, new MESSAGES::AddChatUser());
	AllObjects.Add(-530505962, new MESSAGES::DeleteChatUser());
	AllObjects.Add(-1609667052, new MESSAGES::CreateChat());
	AllObjects.Add(865483769, new MESSAGES::ForwardMessage());
	AllObjects.Add(651135312, new MESSAGES::GetDhConfig());
	AllObjects.Add(-162681021, new MESSAGES::RequestEncryption());
	AllObjects.Add(1035731989, new MESSAGES::AcceptEncryption());
	AllObjects.Add(-304536635, new MESSAGES::DiscardEncryption());
	AllObjects.Add(2031374829, new MESSAGES::SetEncryptedTyping());
	AllObjects.Add(2135648522, new MESSAGES::ReadEncryptedHistory());
	AllObjects.Add(-1451792525, new MESSAGES::SendEncrypted());
	AllObjects.Add(-1701831834, new MESSAGES::SendEncryptedFile());
	AllObjects.Add(852769188, new MESSAGES::SendEncryptedService());
	AllObjects.Add(1436924774, new MESSAGES::ReceivedQueue());
	AllObjects.Add(1259113487, new MESSAGES::ReportEncryptedSpam());
	AllObjects.Add(916930423, new MESSAGES::ReadMessageContents());
	AllObjects.Add(479598769, new MESSAGES::GetAllStickers());
	AllObjects.Add(623001124, new MESSAGES::GetWebPagePreview());
	AllObjects.Add(2106086025, new MESSAGES::ExportChatInvite());
	AllObjects.Add(1051570619, new MESSAGES::CheckChatInvite());
	AllObjects.Add(1817183516, new MESSAGES::ImportChatInvite());
	AllObjects.Add(639215886, new MESSAGES::GetStickerSet());
	AllObjects.Add(-946871200, new MESSAGES::InstallStickerSet());
	AllObjects.Add(-110209570, new MESSAGES::UninstallStickerSet());
	AllObjects.Add(-421563528, new MESSAGES::StartBot());
	AllObjects.Add(-993483427, new MESSAGES::GetMessagesViews());
	AllObjects.Add(-326379039, new MESSAGES::ToggleChatAdmins());
	AllObjects.Add(-1444503762, new MESSAGES::EditChatAdmin());
	AllObjects.Add(363051235, new MESSAGES::MigrateChat());
	AllObjects.Add(-1640190800, new MESSAGES::SearchGlobal());
	AllObjects.Add(2016638777, new MESSAGES::ReorderStickerSets());
	AllObjects.Add(864953444, new MESSAGES::GetDocumentByHash());
	AllObjects.Add(-1080395925, new MESSAGES::SearchGifs());
	AllObjects.Add(-2084618926, new MESSAGES::GetSavedGifs());
	AllObjects.Add(846868683, new MESSAGES::SaveGif());
	AllObjects.Add(1364105629, new MESSAGES::GetInlineBotResults());
	AllObjects.Add(-346119674, new MESSAGES::SetInlineBotResults());
	AllObjects.Add(-1318189314, new MESSAGES::SendInlineBotResult());
	AllObjects.Add(-39416522, new MESSAGES::GetMessageEditData());
	AllObjects.Add(-829299510, new MESSAGES::EditMessage());
	AllObjects.Add(319564933, new MESSAGES::EditInlineBotMessage());
	AllObjects.Add(-2130010132, new MESSAGES::GetBotCallbackAnswer());
	AllObjects.Add(-712043766, new MESSAGES::SetBotCallbackAnswer());
	AllObjects.Add(764901049, new MESSAGES::GetPeerDialogs());
	AllObjects.Add(-1137057461, new MESSAGES::SaveDraft());
	AllObjects.Add(1782549861, new MESSAGES::GetAllDrafts());
	AllObjects.Add(766298703, new MESSAGES::GetFeaturedStickers());
	AllObjects.Add(1527873830, new MESSAGES::ReadFeaturedStickers());
	AllObjects.Add(1587647177, new MESSAGES::GetRecentStickers());
	AllObjects.Add(958863608, new MESSAGES::SaveRecentSticker());
	AllObjects.Add(-1986437075, new MESSAGES::ClearRecentStickers());
	AllObjects.Add(1475442322, new MESSAGES::GetArchivedStickers());
	AllObjects.Add(1706608543, new MESSAGES::GetMaskStickers());
	AllObjects.Add(-866424884, new MESSAGES::GetAttachedStickers());
	AllObjects.Add(-1896289088, new MESSAGES::SetGameScore());
	AllObjects.Add(363700068, new MESSAGES::SetInlineGameScore());
	AllObjects.Add(-400399203, new MESSAGES::GetGameHighScores());
	AllObjects.Add(-1609667052, new MESSAGES::GetInlineGameHighScores());
	AllObjects.Add(-1609667052, new MESSAGES::GetCommonChats());
	AllObjects.Add(-341307408, new MESSAGES::GetAllChats());
	AllObjects.Add(852135825, new MESSAGES::GetWebPage());
	AllObjects.Add(847887978, new MESSAGES::ToggleDialogPin());
	AllObjects.Add(-1784678844, new MESSAGES::ReorderPinnedDialogs());
	AllObjects.Add(-497756594, new MESSAGES::GetPinnedDialogs());
	AllObjects.Add(-436833542, new MESSAGES::SetBotShippingResults());
	AllObjects.Add(-1609667052, new MESSAGES::SetBotPrecheckoutResults());
	AllObjects.Add(1369162417, new MESSAGES::UploadMedia());
	AllObjects.Add(-914493408, new MESSAGES::SendScreenshotNotification());
	AllObjects.Add(567151374, new MESSAGES::GetFavedStickers());
	AllObjects.Add(-1174420133, new MESSAGES::FaveSticker());
	AllObjects.Add(1180140658, new MESSAGES::GetUnreadMentions());
	AllObjects.Add(-304838614, new UPDATES::GetState());
	AllObjects.Add(630429265, new UPDATES::GetDifference());
	AllObjects.Add(-1609667052, new UPDATES::GetChannelDifference());
	AllObjects.Add(-256159406, new PHOTOS::UpdateProfilePhoto());
	AllObjects.Add(1328726168, new PHOTOS::UploadProfilePhoto());
	AllObjects.Add(-2016444625, new PHOTOS::DeletePhotos());
	AllObjects.Add(-1848823128, new PHOTOS::GetUserPhotos());
	AllObjects.Add(-1291540959, new UPLOAD::SaveFilePart());
	AllObjects.Add(-475607115, new UPLOAD::GetFile());
	AllObjects.Add(-562337987, new UPLOAD::SaveBigFilePart());
	AllObjects.Add(619086221, new UPLOAD::GetWebFile());
	AllObjects.Add(536919235, new UPLOAD::GetCdnFile());
	AllObjects.Add(452533257, new UPLOAD::ReuploadCdnFile());
	AllObjects.Add(-149567365, new UPLOAD::GetCdnFileHashes());
	AllObjects.Add(-990308245, new HELP::GetConfig());
	AllObjects.Add(531836966, new HELP::GetNearestDc());
	AllObjects.Add(-1372724842, new HELP::GetAppUpdate());
	AllObjects.Add(1862465352, new HELP::SaveAppLog());
	AllObjects.Add(1295590211, new HELP::GetInviteText());
	AllObjects.Add(-1663104819, new HELP::GetSupport());
	AllObjects.Add(-1877938321, new HELP::GetAppChangelog());
	AllObjects.Add(889286899, new HELP::GetTermsOfService());
	AllObjects.Add(-333262899, new HELP::SetBotUpdatesStatus());
	AllObjects.Add(1375900482, new HELP::GetCdnConfig());
	AllObjects.Add(-871347913, new CHANNELS::ReadHistory());
	AllObjects.Add(-2067661490, new CHANNELS::DeleteMessages());
	AllObjects.Add(-787622117, new CHANNELS::DeleteUserHistory());
	AllObjects.Add(-32999408, new CHANNELS::ReportSpam());
	AllObjects.Add(-1814580409, new CHANNELS::GetMessages());
	AllObjects.Add(618237842, new CHANNELS::GetParticipants());
	AllObjects.Add(1416484774, new CHANNELS::GetParticipant());
	AllObjects.Add(-1609667052, new CHANNELS::GetChannels());
	AllObjects.Add(-1609667052, new CHANNELS::GetFullChannel());
	AllObjects.Add(-192332417, new CHANNELS::CreateChannel());
	AllObjects.Add(333610782, new CHANNELS::EditAbout());
	AllObjects.Add(548962836, new CHANNELS::EditAdmin());
	AllObjects.Add(1450044624, new CHANNELS::EditTitle());
	AllObjects.Add(-248621111, new CHANNELS::EditPhoto());
	AllObjects.Add(283557164, new CHANNELS::CheckUsername());
	AllObjects.Add(890549214, new CHANNELS::UpdateUsername());
	AllObjects.Add(615851205, new CHANNELS::JoinChannel());
	AllObjects.Add(-130635115, new CHANNELS::LeaveChannel());
	AllObjects.Add(429865580, new CHANNELS::InviteToChannel());
	AllObjects.Add(-950663035, new CHANNELS::ExportInvite());
	AllObjects.Add(-1072619549, new CHANNELS::DeleteChannel());
	AllObjects.Add(1231065863, new CHANNELS::ToggleInvites());
	AllObjects.Add(-934882771, new CHANNELS::ExportMessageLink());
	AllObjects.Add(527021574, new CHANNELS::ToggleSignatures());
	AllObjects.Add(-1490162350, new CHANNELS::UpdatePinnedMessage());
	AllObjects.Add(-1920105769, new CHANNELS::GetAdminedPublicChannels());
	AllObjects.Add(-1076292147, new CHANNELS::EditBanned());
	AllObjects.Add(870184064, new CHANNELS::GetAdminLog());
	AllObjects.Add(-359881479, new CHANNELS::SetStickers());
	AllObjects.Add(-357180360, new CHANNELS::ReadMessageContents());
	AllObjects.Add(-1440257555, new BOTS::SendCustomRequest());
	AllObjects.Add(-434028723, new BOTS::AnswerWebhookJSONQuery());
	AllObjects.Add(-1712285883, new PAYMENTS::GetPaymentForm());
	AllObjects.Add(-1601001088, new PAYMENTS::GetPaymentReceipt());
	AllObjects.Add(1997180532, new PAYMENTS::ValidateRequestedInfo());
	AllObjects.Add(730364339, new PAYMENTS::SendPaymentForm());
	AllObjects.Add(578650699, new PAYMENTS::GetSavedInfo());
	AllObjects.Add(-667062079, new PAYMENTS::ClearSavedInfo());
	AllObjects.Add(-1680314774, new STICKERS::CreateStickerSet());
	AllObjects.Add(-143257775, new STICKERS::RemoveStickerFromSet());
	AllObjects.Add(-4795190, new STICKERS::ChangeStickerPosition());
	AllObjects.Add(-2041315650, new STICKERS::AddStickerToSet());
	AllObjects.Add(1430593449, new PHONE::GetCallConfig());
	AllObjects.Add(1536537556, new PHONE::RequestCall());
	AllObjects.Add(1003664544, new PHONE::AcceptCall());
	AllObjects.Add(788404002, new PHONE::ConfirmCall());
	AllObjects.Add(399855457, new PHONE::ReceivedCall());
	AllObjects.Add(2027164582, new PHONE::DiscardCall());
	AllObjects.Add(475228724, new PHONE::SetCallRating());
	AllObjects.Add(662363518, new PHONE::SaveCallDebug());
	AllObjects.Add(-1699363442, new LANGPACK::GetLangPack());
	AllObjects.Add(773776152, new LANGPACK::GetStrings());
	AllObjects.Add(-1609667052, new LANGPACK::GetDifference());
	AllObjects.Add(-2146445955, new LANGPACK::GetLanguages());
	return AllObjects;
}