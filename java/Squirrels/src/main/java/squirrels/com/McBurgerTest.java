package main.java.squirrels.com;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class McBurgerTest {

    McBurger burger;
    @AfterEach
    void tearDown() {
        burger = new McBurger(20, 10);
    }

    @Test
    void passWinter() {
        McBurger burger = new McBurger(20, 10);
        assertEquals(burger.getFoodScore(), 200);

        burger.passWinter();
        assertEquals(burger.getFoodScore(), 80);
        assertEquals(burger.getWinters_passed(), 1);

        burger.passWinter();
        assertEquals(burger.getFoodScore(), 80);
        assertEquals(burger.getWinters_passed(), 2);
    }
}