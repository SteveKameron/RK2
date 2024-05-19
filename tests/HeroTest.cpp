
#include <gtest/gtest.h>
#include "../Hero.h"

TEST(HeroTest, AddAndShowItems) {
    Hero hero("Test Hero", 50, 50, 50);
    Item sword("Sword", 100, 10.0f);
    Item shield("Shield", 80, 15.0f);

    hero.addItem(sword);
    hero.addItem(shield);

    testing::internal::CaptureStdout();
    hero.showItems();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Sword 100 10"), std::string::npos);
    EXPECT_NE(output.find("Shield 80 15"), std::string::npos);
}

TEST(HeroTest, InitialStats) {
    Hero hero("Test Hero", 50, 60, 70);
    EXPECT_EQ(hero.getStrength(), 50);
    EXPECT_EQ(hero.getDexterity(), 60);
    EXPECT_EQ(hero.getWillpower(), 70);
}

TEST(HeroTest, ChangeStats) {
    Hero hero("Test Hero", 50, 60, 70);
    hero.setStrength(100);
    hero.setDexterity(80);
    hero.setWillpower(90);
    EXPECT_EQ(hero.getStrength(), 100);
    EXPECT_EQ(hero.getDexterity(), 80);
    EXPECT_EQ(hero.getWillpower(), 90);
}