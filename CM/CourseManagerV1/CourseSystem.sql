-- MySQL dump 10.13  Distrib 5.7.11, for Win64 (x86_64)
--
-- Host: localhost    Database: CourseSystem
-- ------------------------------------------------------
-- Server version	5.7.11-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
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
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `account` (
  `userid` char(10) NOT NULL,
  `passwd` varchar(16) DEFAULT NULL,
  `role` enum('Teacher','Student','Administer') DEFAULT NULL,
  PRIMARY KEY (`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES ('0000000000','test','Student'),('0000000001','test','Teacher'),('0000000002','test','Administer'),('0000000003','toor','Administer');
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `admin`
--

DROP TABLE IF EXISTS `admin`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `admin` (
  `id` char(10) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `phone` varchar(15) DEFAULT NULL,
  `email` varchar(24) DEFAULT NULL,
  `dept` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `dept` (`dept`),
  CONSTRAINT `admin_ibfk_1` FOREIGN KEY (`id`) REFERENCES `account` (`userid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `admin_ibfk_2` FOREIGN KEY (`dept`) REFERENCES `dept` (`deptname`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `admin`
--

LOCK TABLES `admin` WRITE;
/*!40000 ALTER TABLE `admin` DISABLE KEYS */;
INSERT INTO `admin` VALUES ('0000000002','时一事','13636363636','sys@zju.edu.cn','数学'),('0000000003','黄翔','13434343434','hx@zju.edu.cn','经济');
/*!40000 ALTER TABLE `admin` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `course`
--

DROP TABLE IF EXISTS `course`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `course` (
  `courseid` char(8) NOT NULL,
  `coursename` varchar(30) DEFAULT NULL,
  `dept` varchar(20) DEFAULT NULL,
  `description` varchar(400) DEFAULT NULL,
  PRIMARY KEY (`courseid`),
  KEY `dept` (`dept`),
  CONSTRAINT `course_ibfk_1` FOREIGN KEY (`dept`) REFERENCES `dept` (`deptname`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `course`
--

LOCK TABLES `course` WRITE;
/*!40000 ALTER TABLE `course` DISABLE KEYS */;
INSERT INTO `course` VALUES ('10000000','数据结构','计算机科学与技术','test'),('10000001','高级数据结构','计算机科学与技术','test'),('10000003','数字逻辑设计','计算机科学与技术','test'),('10000056','编译原理','计算机科学与技术','test'),('20000001','线性代数','数学','test'),('30000011','微观经济学','经济','test'),('30000012','宏观经济学','经济','');
/*!40000 ALTER TABLE `course` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dept`
--

DROP TABLE IF EXISTS `dept`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dept` (
  `deptname` varchar(20) NOT NULL,
  PRIMARY KEY (`deptname`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dept`
--

LOCK TABLES `dept` WRITE;
/*!40000 ALTER TABLE `dept` DISABLE KEYS */;
INSERT INTO `dept` VALUES ('数学'),('经济'),('计算机科学与技术');
/*!40000 ALTER TABLE `dept` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `newcourse`
--

DROP TABLE IF EXISTS `newcourse`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `newcourse` (
  `courseid` char(8) NOT NULL,
  `coursename` varchar(30) DEFAULT NULL,
  `dept` varchar(20) DEFAULT NULL,
  `description` varchar(400) DEFAULT NULL,
  `teaid` char(10) NOT NULL,
  PRIMARY KEY (`courseid`,`teaid`),
  KEY `teaid` (`teaid`),
  CONSTRAINT `newcourse_ibfk_1` FOREIGN KEY (`teaid`) REFERENCES `teacher` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `newcourse`
--

LOCK TABLES `newcourse` WRITE;
/*!40000 ALTER TABLE `newcourse` DISABLE KEYS */;
/*!40000 ALTER TABLE `newcourse` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `student` (
  `id` char(10) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `grade` char(4) DEFAULT NULL,
  `class` varchar(24) DEFAULT NULL,
  `phone` varchar(15) DEFAULT NULL,
  `email` varchar(24) DEFAULT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `student_ibfk_1` FOREIGN KEY (`id`) REFERENCES `account` (`userid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES ('0000000000','万不冬','大二','计科1502','13737373737','wbd@zju.edu.cn');
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `takes`
--

DROP TABLE IF EXISTS `takes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `takes` (
  `courseid` char(8) NOT NULL,
  `coursename` varchar(30) DEFAULT NULL,
  `stuid` char(10) NOT NULL,
  `stuname` varchar(20) DEFAULT NULL,
  `teaid` char(10) NOT NULL,
  `teaname` varchar(20) DEFAULT NULL,
  `day` char(4) DEFAULT NULL,
  `starttime` char(2) DEFAULT NULL,
  `endtime` char(2) DEFAULT NULL,
  `pos` varchar(30) DEFAULT NULL,
  `score` varchar(3) DEFAULT NULL,
  PRIMARY KEY (`courseid`,`teaid`,`stuid`),
  KEY `stuid` (`stuid`),
  KEY `teaid` (`teaid`),
  CONSTRAINT `takes_ibfk_1` FOREIGN KEY (`stuid`) REFERENCES `student` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `takes_ibfk_2` FOREIGN KEY (`teaid`) REFERENCES `teacher` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `takes_ibfk_3` FOREIGN KEY (`courseid`) REFERENCES `course` (`courseid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `takes`
--

LOCK TABLES `takes` WRITE;
/*!40000 ALTER TABLE `takes` DISABLE KEYS */;
INSERT INTO `takes` VALUES ('10000000','数据结构','0000000000','万不冬','0000000001','斗尼晚','周一','6','8','西一A309','90'),('20000001','线性代数','0000000000','万不冬','0000000001','斗尼晚','周二','3','5','东一A303','0');
/*!40000 ALTER TABLE `takes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `teacher`
--

DROP TABLE IF EXISTS `teacher`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `teacher` (
  `id` char(10) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `prof` varchar(16) DEFAULT NULL,
  `phone` varchar(15) DEFAULT NULL,
  `email` varchar(24) DEFAULT NULL,
  `dept` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `dept` (`dept`),
  CONSTRAINT `teacher_ibfk_1` FOREIGN KEY (`id`) REFERENCES `account` (`userid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `teacher_ibfk_2` FOREIGN KEY (`dept`) REFERENCES `dept` (`deptname`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `teacher`
--

LOCK TABLES `teacher` WRITE;
/*!40000 ALTER TABLE `teacher` DISABLE KEYS */;
INSERT INTO `teacher` VALUES ('0000000001','斗尼晚','教授','13939393939','dnw1@zju.edu.cn','数学');
/*!40000 ALTER TABLE `teacher` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `teaches`
--

DROP TABLE IF EXISTS `teaches`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `teaches` (
  `courseid` char(8) NOT NULL,
  `coursename` varchar(30) DEFAULT NULL,
  `teaid` char(10) NOT NULL,
  `teaname` varchar(20) DEFAULT NULL,
  `capacity` char(3) DEFAULT NULL,
  `currentstu` char(3) DEFAULT NULL,
  `day` char(4) DEFAULT NULL,
  `starttime` char(2) DEFAULT NULL,
  `endtime` char(2) DEFAULT NULL,
  `pos` varchar(30) DEFAULT NULL,
  `dept` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`courseid`,`teaid`),
  KEY `teaid` (`teaid`),
  KEY `dept` (`dept`),
  CONSTRAINT `teaches_ibfk_1` FOREIGN KEY (`teaid`) REFERENCES `teacher` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `teaches_ibfk_2` FOREIGN KEY (`courseid`) REFERENCES `course` (`courseid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `teaches_ibfk_3` FOREIGN KEY (`dept`) REFERENCES `dept` (`deptname`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `teaches`
--

LOCK TABLES `teaches` WRITE;
/*!40000 ALTER TABLE `teaches` DISABLE KEYS */;
INSERT INTO `teaches` VALUES ('10000000','数据结构','0000000001','斗尼晚','80','79','周一','6','8','西一A309','计算机科学与技术'),('10000001','高级数据结构','0000000001','斗尼晚','120','120','周四','1','2','西二101','计算机科学与技术'),('20000001','线性代数','0000000001','斗尼晚','80','79','周二','3','5','东一A303','数学');
/*!40000 ALTER TABLE `teaches` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-06-30 11:46:56
