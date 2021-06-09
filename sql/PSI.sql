-- --------------------------------------------------------
-- Anfitrião:                    68.183.69.193
-- Versão do servidor:           8.0.25-0ubuntu0.21.04.1 - (Ubuntu)
-- Server OS:                    Linux
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
CREATE DATABASE IF NOT EXISTS `psi` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `psi`;

-- Dumping structure for table psi.contas
DROP TABLE IF EXISTS `contas`;
CREATE TABLE IF NOT EXISTS `contas` (
  `Username` text NOT NULL,
  `Password` text NOT NULL,
  `Saldo` int unsigned NOT NULL DEFAULT '0',
  `IBan` text,
  `Grupo` int NOT NULL DEFAULT '0',
  `Cartao_solicitado` int NOT NULL DEFAULT '0',
  `Cartao_codigo` text,
  `Cartao_entidade` text,
  `Cartao_referencia` text,
  `Cartao_numero` varchar(16) DEFAULT NULL,
  `Cartao_ccv` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Dumping data for table psi.contas: ~2 rows (approximately)
DELETE FROM `contas`;
/*!40000 ALTER TABLE `contas` DISABLE KEYS */;
INSERT INTO `contas` (`Username`, `Password`, `Saldo`, `IBan`, `Grupo`, `Cartao_solicitado`, `Cartao_codigo`, `Cartao_entidade`, `Cartao_referencia`, `Cartao_numero`, `Cartao_ccv`) VALUES
	('admin', 'admin', 1000, 'PT12345678901234567890123', 1, 1, '2907', '53825', '378673902', '7152804730219570', '371');
/*!40000 ALTER TABLE `contas` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
