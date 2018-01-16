/* EXO 00 */
CREATE DATABASE IF NOT EXISTS db_bbeldame;

use db_bbeldame;

SHOW tables;

DESC film;

SELECT * FROM membre;

SELECT * FROM film;

SELECT * FROM fiche_personne;

SELECT * FROM abonnement;

SELECT * FROM genre;

SELECT * FROM salle;

SELECT * FROM distrib;

SELECT * FROM historique_membre;

SELECT * FROM grille_programme;

/* EXO 01 */
CREATE TABLE IF NOT EXISTS ft_table (
	id INT(11) PRIMARY KEY NOT NULL AUTO_INCREMENT,
    login VARCHAR(11) DEFAULT 'toto' NOT NULL,
    groupe ENUM('staff', 'student', 'other') NOT NULL,
    date_de_creation DATE NOT NULL
);

/* EXO 02 */
INSERT INTO ft_table (login, groupe, date_de_creation)
VALUES
('loki', 'staff', '2013-05-01'),
('scadoux', 'student', '2014-01-01'),
('chap', 'staff', '2011-04-27'),
('bambou', 'staff', '2014-03-01'),
('fantomet', 'staff', '2010-04-03');

/* EXO 03 */
INSERT INTO ft_table (login, groupe, date_de_creation)
SELECT nom, 'other', date_naissance FROM fiche_personne
WHERE nom LIKE '%a%' AND CHAR_LENGTH(nom) < 9
ORDER BY nom ASC LIMIT 10;

/* EXO 4 */
UPDATE ft_table SET date_de_creation = DATE_ADD(date_de_creation, INTERVAL 20 YEAR)
WHERE id > 5;

/* EXO 5 */
DELETE FROM ft_table
WHERE id <= 5;

/* EXO 6 */
SELECT titre, resum FROM film
WHERE LOWER(resum) LIKE '%vincent%'
ORDER BY id_film ASC;

/* EXO 7 */
SELECT titre, resum FROM film
WHERE titre LIKE '%42%' OR resum LIKE '%42%'
ORDER BY duree_min ASC;

/* EXO 8 */
SELECT nom, prenom, DATE_FORMAT(date_naissance, '%Y-%m-%d') as 'date de naissance'
FROM fiche_personne
WHERE EXTRACT(YEAR FROM date_naissance) = 1989
ORDER BY nom ASC;

/* EXO 9 */
SELECT COUNT(id_film) AS 'nb_court-metrage'
FROM film
WHERE duree_min <= 42;

/* EXO 10 */
SELECT titre AS 'Titre', resum AS 'Resume', annee_prod
FROM film f
INNER JOIN genre g
ON g.id_genre = f.id_genre
WHERE g.nom = 'erotic'
ORDER BY annee_prod DESC;

/* EXO 11 */
SELECT upper(fp.nom) as 'NOM', fp.prenom, a.prix
FROM fiche_personne fp
INNER JOIN membre m
ON m.id_fiche_perso = fp.id_perso
INNER JOIN abonnement a
ON a.id_abo = m.id_abo
WHERE a.prix > 42
ORDER BY nom ASC, prenom ASC;

/* EXO 12 */
SELECT nom, prenom
FROM fiche_personne
WHERE nom LIKE '%-%' OR prenom LIKE '%-%'
ORDER BY nom ASC, prenom ASC;

/* EXO 13 */
SELECT ROUND(AVG(nbr_siege), 0) as 'moyenne'
FROM salle;

/* EXO 14 */
SELECT etage_salle AS 'etage', SUM(nbr_siege) as 'sieges'
FROM salle
GROUP BY etage_salle
ORDER BY sieges DESC;

/* EXO 15 */
SELECT REVERSE(SUBSTR(telephone, 2)) AS 'enohpelet'
FROM distrib
WHERE SUBSTRING(telephone, 1, 2) = '05';

/* EXO 16 */
SELECT COUNT(*) AS 'films'
FROM historique_membre
WHERE (date BETWEEN '2006-10-30' AND '2007-07-27')
OR MONTH(date) = 12 AND DAY(date) = 24;














