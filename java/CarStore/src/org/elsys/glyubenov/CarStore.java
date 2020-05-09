package org.elsys.glyubenov;

import java.util.*;

public class CarStore {

    private ArrayList<Car> cars = new ArrayList<Car>();

    /**
     * Adds the specified car in the store.
     * @return true if the car was added successfully to the store
     */
    public boolean add(Car car) {
        try {
            cars.add(car);
        }catch (Exception e){
            return false;
        }
        return true;
    }

    /**
     * Adds all of the elements of the specified collection in the store.
     * @return true if the store cars are changed after the execution
     * (i.e. at least one new car is added to the store)
     */
    public boolean addAll(ArrayList<Car> newCars) {

        try {
            for (Car car : newCars){
                cars.add(car);
            }
        }catch (Exception e){
            return false;
        }

        return true;
    }

    /**
     * Removes the specified car from the store.
     * @return true if the car is successfully removed from the store
     */
    public boolean remove(Car car) {

        try {
            int index = 0;
            for (Car car2 : cars) {
                if (car2.registrationNumber == car.registrationNumber) cars.remove(index);
                index += 1;
            }
        }catch (Exception e) {
            return false;
        }
        return true;
    }

    /**
     * Finds a car from the store by its registration number.
     * @throws CarNotFoundException if a car with this
     * registration number is not found in the store
     **/
    public Car getCarByRegistrationNumber(String registrationNumber)throws CarNotFoundException{
        for (Car car : cars){
            if( car.registrationNumber == registrationNumber )return car;
        }
        throw new CarNotFoundException("The car is not found in the store");
    }

    /**
     * Returns all cars of a given model.
     * The cars need to be sorted by year of manufacture (in ascending order).
     */
    public ArrayList<Car> getCarsByModel(Model model) {
        ArrayList<Car>currentCars = new ArrayList<Car>();

        for (Car car : cars){
            if (car.getModel() == model)currentCars.add(car);
        }

        //needs to be sorted
        currentCars.sort(Comparator.comparing(Car::getModel).thenComparing(Car::getYear));

        return currentCars;
    }

    /**
     * Returns all cars sorted by their natural ordering
     * (according to the implementation of the Comparable<Car> interface).
     **/
    public ArrayList<Car> getCars() {
        cars.sort(Comparator.comparing(Car::getModel).thenComparing(Car::getYear));
        return cars;
    }

    /**
     * Returns all cars sorted according to the
     * order induced by the specified comparator.
     */
    public ArrayList<Car> getCars(Comparator<Car> comparator){
        cars.sort(comparator);
        return cars;
    }

    /**
     * Returns all cars sorted according to the
     * given comparator and boolean flag for order.
     * @param isReversed if true, the cars should be returned in reverse order
     */
    public ArrayList<Car> getCars(Comparator<Car> comparator, boolean isReversed) {
        if (isReversed){
            cars.sort(Collections.reverseOrder(comparator));
        }
        else {
            cars.sort(comparator);
        }
        return cars;
    }

    /**
     * Returns the total number of cars in the store.
     */
    public int getNumberOfCars() {
        int count = 0;

        for (Car car : cars) {
            count += 1;
        }
        return count;
    }

    /**
     * Returns the total price of all cars in the store.
     */
    public int getTotalPriceOfCars() {
        int totalPrice = 0;
        for (Car car : cars){
            totalPrice += car.getPrice();
        }
        return totalPrice;
    }
}