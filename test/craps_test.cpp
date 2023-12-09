#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Testing die class functions") 
{
	srand((unsigned) time(NULL));
	Die dice;
	dice.roll();
	REQUIRE(dice.rolled_value() >= 1);
	REQUIRE(dice.rolled_value() <= 6);

	for(int i = 0; i < 10; i++)
	{
		dice.roll();
		REQUIRE(dice.rolled_value() >= 1);
		REQUIRE(dice.rolled_value() <= 6);
	}
}

TEST_CASE("Testing roll class functions") 
{
	srand((unsigned) time(NULL));
	Die dice1;
	Die dice2;
	Roll roll(dice1,dice2);
	roll.roll_die();
	REQUIRE(roll.roll_value() >= 2);
	REQUIRE(roll.roll_value() <= 12);

	for(int i = 0; i < 10; i++)
	{
		roll.roll_die();
		REQUIRE(roll.roll_value() >= 2);
		REQUIRE(roll.roll_value() <= 12);
	}
}

TEST_CASE("Testing shooter class functions")
{
	srand((unsigned) time(NULL));
	Die dice1;
	Die dice2;
	Shooter shooter;
	Roll* roll = shooter.throw_die(dice1,dice2);
	REQUIRE(roll->roll_value() >= 2);
	REQUIRE(roll->roll_value() <= 12);
	for(int i = 0; i < 10; i++)
	{
		roll = shooter.throw_die(dice1,dice2);
		std::cout<<roll->roll_value()<<"\n";
		REQUIRE(roll->roll_value() >= 2);
		REQUIRE(roll->roll_value() <= 12);
	}

}


