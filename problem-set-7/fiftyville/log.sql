-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports
WHERE street = "Humphrey Street" AND date = "2023-07-28";

SELECT * FROM interviews
WHERE date = "2023-07-28" AND location = "Humphrey Street";

SELECT * FROM atm_transactions
WHERE date = "2023-07-28" AND time BETWEEN "12:00:00" AND "23:59:59";

SELECT * FROM phone_calls
WHERE date = "2023-07-28" AND
(
    caller_id IN
    (
        SELECT id FROM people
    ) OR receiver_id IN (
        SELECT id FROM people
    )
);

SELECT * FROM flights
WHERE origin = "Fiftyville Airport" AND date = "2023-07-28";

SELECT * FROM passengers
WHERE flight_id IN
(
    SELECT id FROM flights
    WHERE origin = "Fiftyville Airport" AND date = "2023-07-28"
);

SELECT destination FROM flights
WHERE id IN
(
    SELECT flight_id FROM passengers WHERE person_id = <suspected_thief_id>
);

