# Write your MySQL query statement below
UPDATE salary SET sex = CHAR(ASCII('m')+ASCII('f')-ASCII(sex));