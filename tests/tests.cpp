#include "gtest/gtest.h"
#include "Hero.h"
#include "HeroBuilder.h"
#include <algorithm>
#include <vector>

TEST(HeroBuilderTest, CanBuildWarrior) {
    HeroBuilder builder;
    Hero warrior = builder.buildWarrior();

    EXPECT_EQ(warrior.name, "Conan the Barbarian");
    EXPECT_EQ(warrior.strength, 100);
    EXPECT_EQ(warrior.dexterity, 30);
    EXPECT_EQ(warrior.intelligence, 30);

    std::vector<std::string> expectedItems = {"Sword of Power", "Shield of Resistence"};
    for (const auto& item : expectedItems) {
        EXPECT_TRUE(std::find_if(warrior.inventory.begin(), warrior.inventory.end(), [&](const Item& i) { return i.name == item; }) != warrior.inventory.end());
    }
}

TEST(HeroBuilderTest, CanBuildWizard) {
    HeroBuilder builder;
    Hero wizard = builder.buildWizard();

    EXPECT_EQ(wizard.name, "Gandalf the Grey");
    EXPECT_EQ(wizard.strength, 30);
    EXPECT_EQ(wizard.dexterity, 30);
    EXPECT_EQ(wizard.intelligence, 100);

    std::vector<std::string> expectedItems = {"Holy Stick", "Ancient Dictionary"};
    for (const auto& item : expectedItems) {
        EXPECT_TRUE(std::find_if(wizard.inventory.begin(), wizard.inventory.end(), [&](const Item& i) { return i.name == item; }) != wizard.inventory.end());
    }
}

TEST(HeroBuilderTest, CanBuildRogue) {
    HeroBuilder builder;
    Hero rogue = builder.buildRogue();

    EXPECT_EQ(rogue.name, "Legolas");
    EXPECT_EQ(rogue.strength, 30);
    EXPECT_EQ(rogue.dexterity, 100);
    EXPECT_EQ(rogue.intelligence, 30);

    std::vector<std::string> expectedItems = {"Poisoned Blade", "Bear Slayer"};
    for (const auto& item : expectedItems) {
        EXPECT_TRUE(std::find_if(rogue.inventory.begin(), rogue.inventory.end(), [&](const Item& i) { return i.name == item; }) != rogue.inventory.end());
    }
}
