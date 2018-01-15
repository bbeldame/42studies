CREATE DATABASE IF NOT EXISTS db_bbeldame;

use db_bbeldame;

SHOW tables;

DESC ft_table;

SELECT * FROM ft_table;

SELECT * FROM fiche_personne;

CREATE TABLE IF NOT EXISTS ft_table (
	id INT(11) PRIMARY KEY NOT NULL AUTO_INCREMENT,
    login VARCHAR(11) DEFAULT 'toto' NOT NULL,
    groupe ENUM('staff', 'student', 'other') NOT NULL,
    date_de_creation DATE NOT NULL
);

INSERT INTO ft_table (login, groupe, date_de_creation)
VALUES
('loki', 'staff', '2013-05-01'),
('scadoux', 'student', '2014-01-01'),
('chap', 'staff', '2011-04-27'),
('bambou', 'staff', '2014-03-01'),
('fantomet', 'staff', '2010-04-03');


INSERT INTO ft_table (login, groupe, date_de_creation)
SELECT nom, 'other', date_naissance FROM fiche_personne
WHERE nom LIKE '%a%' AND CHAR_LENGTH(nom) < 9
ORDER BY nom ASC LIMIT 10;

UPDATE ft_table SET date_de_creation = DATE_ADD(date_de_creation, INTERVAL 20 YEAR)
WHERE id <= 5;