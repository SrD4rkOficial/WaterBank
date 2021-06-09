-- --------------------------------------------------------
-- Anfitrião:                    localhost
-- Versão do servidor:           10.4.19-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Versão:              11.2.0.6213
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- Dumping database structure for psi
DROP DATABASE IF EXISTS `psi`;
CREATE DATABASE IF NOT EXISTS `psi` /*!40100 DEFAULT CHARACTER SET utf8mb4 */;
USE `psi`;

-- Dumping structure for table psi.cartoes_pre_pagos
DROP TABLE IF EXISTS `cartoes_pre_pagos`;
CREATE TABLE IF NOT EXISTS `cartoes_pre_pagos` (
  `Titular` text DEFAULT NULL,
  `Numero_do_cartao` int(16) NOT NULL,
  `Validade` int(5) NOT NULL,
  `CCV` int(3) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Dumping data for table psi.cartoes_pre_pagos: ~0 rows (approximately)
DELETE FROM `cartoes_pre_pagos`;
/*!40000 ALTER TABLE `cartoes_pre_pagos` DISABLE KEYS */;
/*!40000 ALTER TABLE `cartoes_pre_pagos` ENABLE KEYS */;

-- Dumping structure for table psi.contas
DROP TABLE IF EXISTS `contas`;
CREATE TABLE IF NOT EXISTS `contas` (
  `Username` text NOT NULL,
  `Password` text NOT NULL,
  `Saldo` int(10) unsigned NOT NULL DEFAULT 0,
  `IBan` text DEFAULT NULL,
  `Cartao_solicitado` int(1) NOT NULL DEFAULT 0,
  `Cartao_codigo` text DEFAULT NULL,
  `Cartao_entidade` text DEFAULT NULL,
  `Cartao_referencia` text DEFAULT NULL,
  `Cartao_numero` varchar(16) DEFAULT NULL,
  `Cartao_ccv` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Dumping data for table psi.contas: ~0 rows (approximately)
DELETE FROM `contas`;
/*!40000 ALTER TABLE `contas` DISABLE KEYS */;
INSERT INTO `contas` (`Username`, `Password`, `Saldo`, `IBan`, `Cartao_solicitado`, `Cartao_codigo`, `Cartao_entidade`, `Cartao_referencia`, `Cartao_numero`, `Cartao_ccv`) VALUES
	('admin', 'admin', 0, 'PT12345678901234567890123', 1, '1658', '99028', '361254526', '5112608485802103', '808'),
	('1', '2', 0, NULL, 0, NULL, '123', '21321', NULL, NULL);
/*!40000 ALTER TABLE `contas` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
