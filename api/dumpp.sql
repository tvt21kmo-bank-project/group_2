-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: netdb
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `account` (
  `idAccount` int NOT NULL AUTO_INCREMENT,
  `AccountNumber` varchar(45) NOT NULL,
  `Balance` decimal(8,2) NOT NULL,
  `CreditLimit` decimal(8,2) NOT NULL,
  `idCustomer` int NOT NULL,
  `isCredit` varchar(1) NOT NULL,
  PRIMARY KEY (`idAccount`),
  KEY `fk_Account_Customer1_idx` (`idCustomer`),
  CONSTRAINT `fk_Account_Customer1` FOREIGN KEY (`idCustomer`) REFERENCES `customer` (`idCustomer`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES (1,'1234-1234',50000.00,50000.00,1,'Y'),(2,'2345-2345',48892.00,0.00,2,'N'),(3,'3456-3456',2294.00,0.00,3,'N'),(4,'4567-4567',9964.00,0.00,1,'N');
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `accountcard`
--

DROP TABLE IF EXISTS `accountcard`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `accountcard` (
  `idAccount` int NOT NULL,
  `idCard` int NOT NULL,
  KEY `fk_table1_Account1_idx` (`idAccount`),
  KEY `fk_table1_Card1_idx` (`idCard`),
  CONSTRAINT `fk_table1_Account1` FOREIGN KEY (`idAccount`) REFERENCES `account` (`idAccount`),
  CONSTRAINT `fk_table1_Card1` FOREIGN KEY (`idCard`) REFERENCES `card` (`idCard`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `accountcard`
--

LOCK TABLES `accountcard` WRITE;
/*!40000 ALTER TABLE `accountcard` DISABLE KEYS */;
INSERT INTO `accountcard` VALUES (1,2),(1,2),(4,2);
/*!40000 ALTER TABLE `accountcard` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `card`
--

DROP TABLE IF EXISTS `card`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card` (
  `idCard` int NOT NULL AUTO_INCREMENT,
  `CardId` varchar(45) NOT NULL,
  `Pin` varchar(255) NOT NULL,
  `idCustomer` int NOT NULL,
  PRIMARY KEY (`idCard`),
  KEY `fk_Card_Customer_idx` (`idCustomer`),
  CONSTRAINT `fk_Card_Customer` FOREIGN KEY (`idCustomer`) REFERENCES `customer` (`idCustomer`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card`
--

LOCK TABLES `card` WRITE;
/*!40000 ALTER TABLE `card` DISABLE KEYS */;
INSERT INTO `card` VALUES (2,'1234-1234','$2a$10$ol4y82k1.zxpbbKzRaI19uAqa4UmRgG.Ullf4lW1E2fZ7EWQD/18m',1),(3,'2345-2345','$2a$10$qsMmJqSM3pOQkoIivGuVMuqbcNObN95SQIuSyoBtR8R98atrlo8xm',2),(4,'3456-3456','$2a$10$7KIQ6v2LhQoy7PcSJY.wzO8axomttH62ebde.JOY0MUrkZ5eA49yq',3),(6,'4567-4567','$2a$10$n2bY8rW1ulXhL6RrpKVcoeKoH4XjOEzOlCDCS8N6JU85JWjs98JGS',1);
/*!40000 ALTER TABLE `card` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customer` (
  `idCustomer` int NOT NULL AUTO_INCREMENT,
  `Name` varchar(45) NOT NULL,
  `Address` varchar(45) NOT NULL,
  `PhoneNumber` varchar(45) NOT NULL,
  PRIMARY KEY (`idCustomer`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES (1,'Mikko Mastermind','Rokkikatu 6','0400582741'),(2,'Cassu aka HejaSverige','Surströmming 44','0400859736'),(3,'Alli WhiteboardLover','Tussitie 294','0400847362');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transactions`
--

DROP TABLE IF EXISTS `transactions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transactions` (
  `idTransactions` int NOT NULL AUTO_INCREMENT,
  `Transaction` varchar(45) NOT NULL,
  `DateTime` datetime(2) NOT NULL,
  `Amount` decimal(8,2) NOT NULL,
  `idAccount` int NOT NULL,
  PRIMARY KEY (`idTransactions`),
  KEY `fk_Transactions_Account1_idx` (`idAccount`),
  CONSTRAINT `fk_Transactions_Account1` FOREIGN KEY (`idAccount`) REFERENCES `account` (`idAccount`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactions`
--

LOCK TABLES `transactions` WRITE;
/*!40000 ALTER TABLE `transactions` DISABLE KEYS */;
INSERT INTO `transactions` VALUES (1,'NOSTO','2021-12-02 18:09:51.00',5.50,1);
/*!40000 ALTER TABLE `transactions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'netdb'
--
/*!50003 DROP PROCEDURE IF EXISTS `getIdAccount` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `getIdAccount`(IN _cardID VARCHAR(45), IN _isCredit VARCHAR(1))
BEGIN
    /* SELECT idAccount ONLY IF ACCOUNT JOINED TO THE CARD FOUND */
    SELECT a.idAccount AS idAccount FROM card c INNER JOIN accountcard ac ON c.idCard=ac.idCard INNER JOIN account a ON ac.idAccount = a.idAccount WHERE cardId = _cardId AND isCredit=_isCredit;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `getPinCheckCredit` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `getPinCheckCredit`(IN _cardID VARCHAR(45))
BEGIN
	/* DECLARE INTERNAL VARIABLES AND SET DEFAULTS */
    DECLARE _Pin VARCHAR(255);
    DECLARE _isCredit VARCHAR(1);
    SET _Pin = '';
    SET _isCredit = 'N'; 
	/* SELECT _Pin IF card EXISTS */ 
    SELECT Pin INTO _Pin FROM card WHERE cardId = _cardID;
    /* SELECT isCredit ONLY IF ANY ACCOUT JOINED TO THE CARD HAS isCredit = 'Y' */
    SELECT isCredit INTO _isCredit FROM card c INNER JOIN accountcard ac ON c.idCard=ac.idCard INNER JOIN account a ON ac.idAccount = a.idAccount WHERE cardId = _cardId AND isCredit='Y';
    
    /* FINALLY SELECT INTERNAL VARIABLES IF CARD DID EXIST */
    IF _Pin <> '' THEN 
		SELECT _Pin AS Pin, _isCredit AS isCredit;
	END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `getTransactions` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `getTransactions`(IN _idAccount INT, IN _page INT, IN _transactionsPerPage INT)
BEGIN
	DECLARE _offset, _pagesCount INT;
    DECLARE _Balance DECIMAL(8,2);
	
    /* Haetaan tilin saldo ja tapahtumien sivujen määrä */ 
    SELECT Balance INTO _Balance FROM account WHERE idAccount = _idAccount;
    SELECT CEIL(COUNT(*) / _transactionsPerPage) INTO _pagesCount FROM transactions WHERE idAccount = _idAccount;
    
    /* Haetaan tapahtumat sivutuksen mukaan */
    SET _offset = (_page - 1) * _transactionsPerPage;
	SELECT DateTime, Transaction, Amount, _Balance AS 'TotalBalance', _pagesCount AS 'PagesCount' FROM transactions WHERE idAccount = _idAccount ORDER BY DateTime DESC LIMIT _offset, _transactionsPerPage;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `withdrawMoney` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `withdrawMoney`(IN _idAccount INT, IN _amount DECIMAL(8,2))
BEGIN
	DECLARE _newBalance DECIMAL(8,2);
    DECLARE _creditLimit DECIMAL(8,2);
    DECLARE _isCredit VARCHAR(1);
   
	/* Selvitä voiko tililtä nostaa (debit-tili: Balance - amount >= 0, credit-tili: Balance - amount >= 0-creditLimit(neg)) */
    SELECT (Balance - _amount), isCredit, CreditLimit INTO _newBalance, _isCredit, _creditLimit FROM account WHERE idAccount = _idAccount;
    IF (_isCredit IS NOT NULL) THEN
		IF (_newBalance >= 0 AND _isCredit = 'N') OR (_newBalance >= 0 - _creditLimit AND _isCredit = 'Y') THEN
			BEGIN
				/* OK: Päivitä uusi Balance ja palauta Y */
				UPDATE account SET Balance = _newBalance WHERE idAccount = _idAccount;
				SELECT 'Y' AS 'withdrawOK', CONCAT('New balance:', _newBalance) AS 'message';
			END;		
		ELSE
			/* NOK: Palauta 'N' */
			SELECT 'N' AS 'withdrawOK', 'Account exceeded!' AS 'message';
		END IF;
    END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-02 18:12:52
