package main.java.squirrels.com;

import static org.junit.jupiter.api.Assertions.*;

class BaseFoodTest {

    Food food;
    @org.junit.jupiter.api.BeforeEach
    void setUp() {
        food = new Food(10, 10);
    }

    @org.junit.jupiter.api.Test
    void getFoodScore() {
        Food food = new Food(10, 10);
        assertEquals(food.getFoodScore(), 100);

        food = new Food(20, 10);
        assertEquals(food.getFoodScore(), 200);

        food = new Food(10, 20);
        assertEquals(food.getFoodScore(), 200);
    }

}