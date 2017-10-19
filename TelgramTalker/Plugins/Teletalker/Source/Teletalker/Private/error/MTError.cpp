#include "MTError.h"

AUTH_KEY_UNREGISTERED::AUTH_KEY_UNREGISTERED() : std::runtime_error((char *) *Message)
{
}

const char* AUTH_KEY_UNREGISTERED::what() const throw()
{
	return (char *)*Message;
}

const char* AUTH_KEY_INVALID::what() const throw()
{
	return "The key is invalid";
}

const char* USER_DEACTIVATED::what() const throw()
{
	return "The user has been deleted/deactivated";
}

const char* SESSION_REVOKED::what() const throw()
{
	return "The authorization has been invalidated, because of the user terminating all sessions";
}


SESSION_EXPIRED::SESSION_EXPIRED() : std::runtime_error((char *)*Message)
{

}

const char* SESSION_EXPIRED::what() const throw()
{
	return (char *)*Message;
}

const char* ACTIVE_USER_REQUIRED::what() const throw()
{
	return "The method is only available to already activated users";
}

const char* AUTH_KEY_PERM_EMPTY::what() const throw()
{
	return "The method is unavailable for temporary authorization key, not bound to permanent";
}


PHONE_MIGRATE::PHONE_MIGRATE() : std::runtime_error((char *)*Message)
{

}

const char* PHONE_MIGRATE::what() const throw()
{
	return (char *)*Message;
}
