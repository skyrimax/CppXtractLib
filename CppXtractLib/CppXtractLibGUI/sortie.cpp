#include "QtUtil.h"


// Création d'une QString pour insérer les points
const QString dots("...");

// Définition de la fonction qui tronque le nom de fichier
QString complyFileName(const QString& mCurrentDirectory, size_t mMaxLengthToDisplay) {
	
	// Si le chemin du fichier a moins de caractère (défini par mMaxLengthToDisplay = 50)
	if (mCurrentDirectory.length() <= mMaxLengthToDisplay)
		return mCurrentDirectory;
	
	// Trouve le premier et les 2 prochains "/"
	auto espaceavant1 = mCurrentDirectory.indexOf(QChar('/'), 0, Qt::CaseSensitive);
	auto espaceavant2 = mCurrentDirectory.indexOf(QChar('/'), espaceavant1+1, Qt::CaseSensitive);
	auto espaceavant3 = mCurrentDirectory.indexOf(QChar('/'), espaceavant2 + 2, Qt::CaseSensitive);

	// Trouve le dernier et les 2 derniers "/"
	auto espaceapres1 = mCurrentDirectory.lastIndexOf(QChar('/'), Qt::CaseSensitive);
	auto espaceapres2 = mCurrentDirectory.lastIndexOf(QChar('/'), espaceapres1-1, Qt::CaseSensitive);
	auto espaceapres3 = mCurrentDirectory.lastIndexOf(QChar('/'), espaceapres2 - 2, Qt::CaseSensitive);

	// Création d'une string avec les indentations calculées
	auto avant = mCurrentDirectory.left(std::ceil(espaceavant3+1));
	auto apres = mCurrentDirectory.right(mCurrentDirectory.length()-std::floor(espaceapres3));

	// Retourne la somme des 3 strings
	return avant + dots + apres;

}