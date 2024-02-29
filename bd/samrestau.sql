-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : jeu. 29 fév. 2024 à 20:41
-- Version du serveur : 10.4.32-MariaDB
-- Version de PHP : 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `samrestau`
--

-- --------------------------------------------------------

--
-- Structure de la table `profils`
--

CREATE TABLE `profils` (
  `id` tinyint(3) NOT NULL,
  `nom` varchar(50) NOT NULL DEFAULT '',
  `m1_01` tinyint(1) NOT NULL DEFAULT 0,
  `m1_02` tinyint(1) NOT NULL DEFAULT 0,
  `m1_03` tinyint(1) NOT NULL DEFAULT 0,
  `m1_04` tinyint(1) NOT NULL DEFAULT 0,
  `m1_05` tinyint(1) NOT NULL DEFAULT 0,
  `m1_06` tinyint(1) NOT NULL DEFAULT 0,
  `m1_07` tinyint(1) NOT NULL DEFAULT 0,
  `m1_08` tinyint(1) NOT NULL DEFAULT 0,
  `m1_09` tinyint(1) NOT NULL DEFAULT 0,
  `m2_01` tinyint(1) NOT NULL DEFAULT 0,
  `m2_02` tinyint(1) NOT NULL DEFAULT 0,
  `m2_03` tinyint(1) NOT NULL DEFAULT 0,
  `m2_04` tinyint(1) NOT NULL DEFAULT 0,
  `m2_05` tinyint(1) NOT NULL DEFAULT 0,
  `m2_06` tinyint(1) NOT NULL DEFAULT 0,
  `m2_07` tinyint(1) NOT NULL DEFAULT 0,
  `m2_08` tinyint(1) NOT NULL DEFAULT 0,
  `m2_09` tinyint(1) NOT NULL DEFAULT 0,
  `m3_01` tinyint(1) NOT NULL DEFAULT 0,
  `m3_02` tinyint(1) NOT NULL DEFAULT 0,
  `m3_03` tinyint(1) NOT NULL DEFAULT 0,
  `m3_04` tinyint(1) NOT NULL DEFAULT 0,
  `m3_05` tinyint(1) NOT NULL DEFAULT 0,
  `m3_06` tinyint(1) NOT NULL DEFAULT 0,
  `m3_07` tinyint(1) NOT NULL DEFAULT 0,
  `m3_08` tinyint(1) NOT NULL DEFAULT 0,
  `m3_09` tinyint(1) NOT NULL DEFAULT 0,
  `m4_01` tinyint(1) NOT NULL DEFAULT 0,
  `m4_02` tinyint(1) NOT NULL DEFAULT 0,
  `m4_03` tinyint(1) NOT NULL DEFAULT 0,
  `m4_04` tinyint(1) NOT NULL DEFAULT 0,
  `m4_05` tinyint(1) NOT NULL DEFAULT 0,
  `m4_06` tinyint(1) NOT NULL DEFAULT 0,
  `m4_07` tinyint(1) NOT NULL DEFAULT 0,
  `m4_08` tinyint(1) NOT NULL DEFAULT 0,
  `m4_09` tinyint(1) NOT NULL DEFAULT 0,
  `m5_01` tinyint(1) NOT NULL DEFAULT 0,
  `m5_02` tinyint(1) NOT NULL DEFAULT 0,
  `m5_03` tinyint(1) NOT NULL DEFAULT 0,
  `m5_04` tinyint(1) NOT NULL DEFAULT 0,
  `m5_05` tinyint(1) NOT NULL DEFAULT 0,
  `m5_06` tinyint(1) NOT NULL DEFAULT 0,
  `m5_07` tinyint(1) NOT NULL DEFAULT 0,
  `m5_08` tinyint(1) NOT NULL DEFAULT 0,
  `m5_09` tinyint(1) NOT NULL DEFAULT 0,
  `m6_01` tinyint(1) NOT NULL DEFAULT 0,
  `m6_02` tinyint(1) NOT NULL DEFAULT 0,
  `m6_03` tinyint(1) NOT NULL DEFAULT 0,
  `m6_04` tinyint(1) NOT NULL DEFAULT 0,
  `m6_05` tinyint(1) NOT NULL DEFAULT 0,
  `m6_06` tinyint(1) NOT NULL DEFAULT 0,
  `m6_07` tinyint(1) NOT NULL DEFAULT 0,
  `m6_08` tinyint(1) NOT NULL DEFAULT 0,
  `m6_09` tinyint(1) NOT NULL DEFAULT 0,
  `m7_01` tinyint(1) NOT NULL DEFAULT 0,
  `m7_02` tinyint(1) NOT NULL DEFAULT 0,
  `m7_03` tinyint(1) NOT NULL DEFAULT 0,
  `m7_04` tinyint(1) NOT NULL DEFAULT 0,
  `m7_05` tinyint(1) NOT NULL DEFAULT 0,
  `m7_06` tinyint(1) NOT NULL DEFAULT 0,
  `m7_07` tinyint(1) NOT NULL DEFAULT 0,
  `m7_08` tinyint(1) NOT NULL DEFAULT 0,
  `m7_09` tinyint(1) NOT NULL DEFAULT 0,
  `m8_01` tinyint(1) NOT NULL DEFAULT 0,
  `m8_02` tinyint(1) NOT NULL DEFAULT 0,
  `m8_03` tinyint(1) NOT NULL DEFAULT 0,
  `m8_04` tinyint(1) NOT NULL DEFAULT 0,
  `m8_05` tinyint(1) NOT NULL DEFAULT 0,
  `m8_06` tinyint(1) NOT NULL DEFAULT 0,
  `m8_07` tinyint(1) NOT NULL DEFAULT 0,
  `m8_08` tinyint(1) NOT NULL DEFAULT 0,
  `m8_09` tinyint(1) NOT NULL DEFAULT 0,
  `m9_01` tinyint(1) NOT NULL DEFAULT 0,
  `m9_02` tinyint(1) NOT NULL DEFAULT 0,
  `m9_03` tinyint(1) NOT NULL DEFAULT 0,
  `m9_04` tinyint(1) NOT NULL DEFAULT 0,
  `m9_05` tinyint(1) NOT NULL DEFAULT 0,
  `m9_06` tinyint(1) NOT NULL DEFAULT 0,
  `m9_07` tinyint(1) NOT NULL DEFAULT 0,
  `m9_08` tinyint(1) NOT NULL DEFAULT 0,
  `m9_09` tinyint(1) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `profils`
--

INSERT INTO `profils` (`id`, `nom`, `m1_01`, `m1_02`, `m1_03`, `m1_04`, `m1_05`, `m1_06`, `m1_07`, `m1_08`, `m1_09`, `m2_01`, `m2_02`, `m2_03`, `m2_04`, `m2_05`, `m2_06`, `m2_07`, `m2_08`, `m2_09`, `m3_01`, `m3_02`, `m3_03`, `m3_04`, `m3_05`, `m3_06`, `m3_07`, `m3_08`, `m3_09`, `m4_01`, `m4_02`, `m4_03`, `m4_04`, `m4_05`, `m4_06`, `m4_07`, `m4_08`, `m4_09`, `m5_01`, `m5_02`, `m5_03`, `m5_04`, `m5_05`, `m5_06`, `m5_07`, `m5_08`, `m5_09`, `m6_01`, `m6_02`, `m6_03`, `m6_04`, `m6_05`, `m6_06`, `m6_07`, `m6_08`, `m6_09`, `m7_01`, `m7_02`, `m7_03`, `m7_04`, `m7_05`, `m7_06`, `m7_07`, `m7_08`, `m7_09`, `m8_01`, `m8_02`, `m8_03`, `m8_04`, `m8_05`, `m8_06`, `m8_07`, `m8_08`, `m8_09`, `m9_01`, `m9_02`, `m9_03`, `m9_04`, `m9_05`, `m9_06`, `m9_07`, `m9_08`, `m9_09`) VALUES
(1, 'Développeurs', 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
(2, 'Testeur', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(3, 'Test-------', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(4, 'Contrôleurs', 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

CREATE TABLE `users` (
  `id` int(3) NOT NULL,
  `id_profil` tinyint(3) NOT NULL,
  `ca` varchar(16) DEFAULT '',
  `pseudo` varchar(50) DEFAULT '',
  `mp` varchar(99) DEFAULT NULL,
  `etat` int(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `users`
--

INSERT INTO `users` (`id`, `id_profil`, `ca`, `pseudo`, `mp`, `etat`) VALUES
(1, 1, '-1', 'Global', '-1', 1),
(5, 2, 'test', '', 'test', 1),
(21, 4, 'essai', 'essai', 'essai', 1);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `profils`
--
ALTER TABLE `profils`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD KEY `users_ndx_id_profil` (`id_profil`) USING BTREE;

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `profils`
--
ALTER TABLE `profils`
  MODIFY `id` tinyint(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `users`
--
ALTER TABLE `users`
  ADD CONSTRAINT `users_fk_id_profil` FOREIGN KEY (`id_profil`) REFERENCES `profils` (`id`) ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
