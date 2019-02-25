#include "QtUtil.h"
#include "stdafx.h"

QString complyFileName(const QString & completeFileName, size_t maxLength)
{
	auto length{ maxLength / 2 };
	int pos1, pos2;
	QString str1, str2, string1, string2;
	QString strP("...");

	if (completeFileName.length() <= maxLength)
	{
		return completeFileName;
	}
	else
	{
		str1 = completeFileName.left(length);
		str2 = completeFileName.right(length);

		pos1 = str1.lastIndexOf(QChar('/'));
		string1 = str1.left(pos1 + 1);

		pos2 = str2.indexOf(QChar('/'));
		string2 = str2.right(length-pos2);
	
		return string1 + strP+ string2;
	}
}