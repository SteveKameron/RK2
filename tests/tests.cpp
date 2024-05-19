#include <gtest/gtest.h>
#include "Hero.h"

TEST(HeroTest, Constructor) {
    Hero hero("Warrior", 15, 10, 12);
    EXPECT_EQ(hero.name, "Warrior");
    EXPECT_EQ(hero.strength, 15);
    EXPECT_EQ(hero.dexterity, 10);
    EXPECT_EQ(hero.willpower, 12);
    EXPECT_TRUE(hero.inventory.empty());
}

TEST(HeroTest, AddItem) {
    Hero hero("Mage", 8, 14, 18);
    Item item("Staff", 5, 10);
    hero.addItem(item);

    EXPECT_EQ(hero.inventory.size(), 1);
    EXPECT_EQ(hero.inventory.front().name, "Staff");
    EXPECT_EQ(hero.inventory.front().weight, 5);
    EXPECT_EQ(hero.inventory.front().cost, 10);
}

TEST(HeroTest, ShowItems) {
    Hero hero("Ranger", 12, 18, 10);
    Item item1("Bow", 3, 20);
    Item item2("Arrow", 1, 2);
    hero.addItem(item1);
    hero.addItem(item2);

    testing::internal::CaptureStdout();
    hero.showItems();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Bow"), std::string::npos);
    EXPECT_NE(output.find("Arrow"), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
