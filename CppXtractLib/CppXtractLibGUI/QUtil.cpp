#include "QtUtil.h"

const QString dots("...");

QString complyFileName(const QString& mCurrentDirectory, size_t mMaxLengthToDisplay) {
	if (mCurrentDirectory.length() <= mMaxLengthToDisplay)
		return mCurrentDirectory;
	
	auto espaceavant1 = mCurrentDirectory.indexOf(QChar('/'), 0, Qt::CaseSensitive);
	auto espaceavant2 = mCurrentDirectory.indexOf(QChar('/'), espaceavant1+1, Qt::CaseSensitive);

	auto espaceapres1 = mCurrentDirectory.lastIndexOf(QChar('/'), Qt::CaseSensitive);
	auto espaceapres2 = mCurrentDirectory.lastIndexOf(QChar('/'), espaceapres1-1, Qt::CaseSensitive);

	auto avant = mCurrentDirectory.left(std::ceil(espaceavant2+1));
	auto apres = mCurrentDirectory.right(mCurrentDirectory.length()-std::floor(espaceapres2));

	return avant + dots + apres;

}