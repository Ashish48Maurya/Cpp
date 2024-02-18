CREATE DATABASE Cricket;
USE Cricket;

-- Create the `Match` table
CREATE TABLE `Match` (
    matchid INT PRIMARY KEY,
    team1 VARCHAR(255),
    team2 VARCHAR(255),
    ground VARCHAR(255),
    date DATE,
    winner VARCHAR(255)
);

-- Create the Player table
CREATE TABLE Player (
    playerid INT PRIMARY KEY,
    lname VARCHAR(255),
    fname VARCHAR(255),
    country VARCHAR(255),
    year_of_born INT,
    birthplace VARCHAR(255)
);

-- Create the Batting table
CREATE TABLE Batting (
    matchid INT,
    playerid INT,
    batting_order INT,
    runs INT,
    fours INT,
    sixes INT,
    PRIMARY KEY (matchid, playerid),
    FOREIGN KEY (matchid) REFERENCES `Match`(matchid),
    FOREIGN KEY (playerid) REFERENCES Player(playerid)
);

-- Create the Bowling table
CREATE TABLE Bowling (
    matchid INT,
    playerid INT,
    overs FLOAT,
    maidens INT,
    runs INT,
    wickets INT,
    PRIMARY KEY (matchid, playerid),
    FOREIGN KEY (matchid) REFERENCES `Match`(matchid),
    FOREIGN KEY (playerid) REFERENCES Player(playerid)
);

-- Insert data into the `Match` table
INSERT INTO `Match` (matchid, team1, team2, ground, date, winner)
VALUES
    (100, 'Team A', 'Team B', 'Ground 1', '2023-01-10', 'Team A'),
    (2, 'Team C', 'Team D', 'Ground 2', '2023-02-15', 'Team D'),
    (3, 'Team E', 'Team F', 'Ground 3', '2023-03-20', 'Team E'),
    (4, 'Team G', 'Team H', 'Ground 4', '2023-04-25', 'Team H'),
    (5, 'Team I', 'Team J', 'Ground 5', '2023-05-30', 'Team I');

-- Insert data into the Player tableINSERT INTO Player (playerid, lname, fname, country, year_of_born, birthplace)
INSERT INTO Player (playerid, lname, fname, country, year_of_born, birthplace)
VALUES
    (1, 'Doe', 'John', 'USA', 1990, 'New York'),
    (2, 'Smith', 'Alice', 'China', 1985, 'London'),
    (3, 'Lee', 'David', 'Australia', 1995, 'Sydney'),
    (4, 'Garcia', 'Maria', 'Spain', 1992, 'Madrid'),
    (5, 'Wang', 'Li', 'China', 1988, 'Beijing');

-- Insert data into the Batting table
INSERT INTO Batting (matchid, playerid, batting_order, runs, fours, sixes)
VALUES
    (100, 1, 1, 75, 9, 3),
    (1, 2, 2, 62, 5, 2),
    (2, 3, 1, 88, 11, 4),
    (2, 4, 2, 45, 4, 1),
    (3, 5, 1, 102, 12, 6);

-- Insert data into the Bowling table
INSERT INTO Bowling (matchid, playerid, overs, maidens, runs, wickets)
VALUES
    (100, 1, 6.2, 1, 30, 3),
    (1, 2, 5.4, 0, 42, 1),
    (2, 3, 7.1, 2, 26, 4),
    (2, 4, 8.0, 0, 60, 2),
    (3, 5, 9.3, 1, 38, 5);

-- Insert a new player into the Player table
INSERT INTO Player VALUES (123,'Smith', 'John', 'Canada', 1993, 'Toronto');

select fname,lname from Player where year_of_born > 1990;

SELECT B.matchid
FROM Batting B
JOIN Player P ON B.playerid = P.playerid
WHERE P.fname = "John";

SELECT DISTINCT B.playerid
FROM Batting B
JOIN Bowling Bo ON B.playerid = Bo.playerid
WHERE B.matchid = 100;


SELECT P.fname, P.lname, AVG(B.runs) AS average_runs
FROM Player P
INNER JOIN Batting B ON P.playerid = B.playerid
WHERE P.country = 'China'
GROUP BY P.playerid
ORDER BY average_runs DESC;