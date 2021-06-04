-- --------------------------------------------------------
-- Anfitrião:                    192.168.56.1
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
  `IBan` text DEFAULT NULL,
  `Cartao_solicitado` int(1) NOT NULL DEFAULT 0,
  `Cartao_ativo` int(1) NOT NULL DEFAULT 0,
  `Cartao_codigo` int(1) DEFAULT NULL,
  `Cartao_entidade` int(5) DEFAULT NULL,
  `Cartao_referencia` int(9) DEFAULT NULL,
  `Cartao_numero` int(16) DEFAULT NULL,
  `Cartao_validade` int(5) DEFAULT NULL,
  `Cartao_ccv` int(3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Dumping data for table psi.contas: ~1 rows (approximately)
DELETE FROM `contas`;
/*!40000 ALTER TABLE `contas` DISABLE KEYS */;
INSERT INTO `contas` (`Username`, `Password`, `IBan`, `Cartao_solicitado`, `Cartao_ativo`, `Cartao_codigo`, `Cartao_entidade`, `Cartao_referencia`, `Cartao_numero`, `Cartao_validade`, `Cartao_ccv`) VALUES
	('srd4rk', '123', NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL);
/*!40000 ALTER TABLE `contas` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
