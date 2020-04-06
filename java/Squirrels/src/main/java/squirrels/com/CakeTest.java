package main.java.squirrels.com;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CakeTest {

    Cake cake;
    @BeforeEach
    void setUp() {
        cake = new Cake(20, 10);
    }

    @Test
    void passWinter() {
        Cake cake = new Cake(20, 10);
        assertEquals(cake.getFoodScore(), 200);

        cake.passWinter();
        assertEquals(cake.getFoodScore(), 137.26, 0.01);
        assertEquals(cake.getWinters_passed(), 1);

        cake.passWinter();
        assertEquals(cake.getFoodScore(), 47.03, 0.01);
        assertEquals(cake.getWinters_passed(), 2);
    }
}