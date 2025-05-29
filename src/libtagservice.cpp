// Local Includes
#include "libtagservice.h"

// External Includes
#include <nap/core.h>
#include <nap/resourcemanager.h>
#include <nap/logger.h>
#include <iostream>

RTTI_BEGIN_CLASS_NO_DEFAULT_CONSTRUCTOR(nap::libtagService)
	RTTI_CONSTRUCTOR(nap::ServiceConfiguration*)
RTTI_END_CLASS

namespace nap
{
	bool libtagService::init(nap::utility::ErrorState& errorState)
	{
		//Logger::info("Initializing libtagService");
		return true;
	}


	void libtagService::update(double deltaTime)
	{
	}
	

	void libtagService::getDependentServices(std::vector<rtti::TypeInfo>& dependencies)
	{
	}
	

	void libtagService::shutdown()
	{
	}
}
