#include <gtest/gtest.h>
#include "Hero.h"
#include "Item.h"

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
    Spellbook spellbook("Tome of Fire", 20, 50.0f);
    hero.addItem(spellbook);

    ASSERT_EQ(hero.inventory.size(), 1);
    Item& addedItem = hero.inventory.front();
    EXPECT_EQ(addedItem.name, "Tome of Fire");
    EXPECT_EQ(addedItem.power, 20);
    EXPECT_EQ(addedItem.cost, 50.0f);
}

TEST(HeroTest, AddMultipleItems) {
    Hero hero("Ranger", 12, 18, 10);
    Bow bow("Elven Bow", 15, 75.0f);
    Dagger dagger("Poisoned Dagger", 8, 25.0f);
    hero.addItem(bow);
    hero.addItem(dagger);

    ASSERT_EQ(hero.inventory.size(), 2);

    Item& item1 = hero.inventory.front();
    EXPECT_EQ(item1.name, "Elven Bow");
    EXPECT_EQ(item1.power, 15);
    EXPECT_EQ(item1.cost, 75.0f);

    Item& item2 = hero.inventory.back();
    EXPECT_EQ(item2.name, "Poisoned Dagger");
    EXPECT_EQ(item2.power, 8);
    EXPECT_EQ(item2.cost, 25.0f);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
