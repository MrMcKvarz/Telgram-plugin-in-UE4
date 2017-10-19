#pragma once
#include <exception>
#include <stdexcept>
#include "Engine.h"

/*401 -- UNAUTHORIZED*/

#pragma region Error401
class AUTH_KEY_UNREGISTERED : public std::runtime_error
{
	FString Message = "The key is not registered in the system";
public:
	AUTH_KEY_UNREGISTERED();

	virtual const char* what() const throw();

};


class AUTH_KEY_INVALID : public std::runtime_error
{
public:
	AUTH_KEY_INVALID();

	virtual const char* what() const throw();

};

class USER_DEACTIVATED : public std::runtime_error
{
public:
	USER_DEACTIVATED();

	virtual const char* what() const throw();

};


class SESSION_REVOKED : public std::runtime_error
{
public:
	SESSION_REVOKED();

	virtual const char* what() const throw();

};

class SESSION_EXPIRED : public std::runtime_error
{

	FString Message = "The authorization has expired";
public:
	SESSION_EXPIRED();

	virtual const char* what() const throw();

};

class ACTIVE_USER_REQUIRED : public std::runtime_error
{
public:
	ACTIVE_USER_REQUIRED();

	virtual const char* what() const throw();

};

class AUTH_KEY_PERM_EMPTY : public std::runtime_error
{
public:
	AUTH_KEY_PERM_EMPTY();

	virtual const char* what() const throw();

};
#pragma endregion


/*303 ERROR_SEE_OTHER*/

class PHONE_MIGRATE : public std::runtime_error
{
	FString Message = "the phone number a user is trying to use for authorization is associated with a different data center";
	int32 DC_ID;
public:
	PHONE_MIGRATE();
	PHONE_MIGRATE(int32 DC_ID_Value) : PHONE_MIGRATE() { DC_ID = DC_ID_Value; }
	
	virtual const char* what() const throw();
	int32 GetID() { return DC_ID; }
};