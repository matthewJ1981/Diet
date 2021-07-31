#pragma once
#include <gtest/gtest.h>
#include "..\DietApp.h"
#include "..\Util.h"
#include "..\DietAppImplementation.h"
#include <fstream>
#include <iostream>


class DietAppTest : public ::testing::Test
{
protected:
	void SetUp() override
	{	
		;
	}

	void TearDown() override
	{
		;
	}

	Diet::Internal::DietAppImplementation di;
};

