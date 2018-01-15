CREATE TABLE IF NOT EXISTS ft_table (
	id INT(11) PRIMARY KEY NOT NULL AUTO_INCREMENT,
	login VARCHAR(11) DEFAULT 'toto' NOT NULL,
	groupe ENUM('staff', 'student', 'other') NOT NULL,
	date_de_creation DATE NOT NULL
);
