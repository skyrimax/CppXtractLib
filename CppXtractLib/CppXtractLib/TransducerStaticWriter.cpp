#include "TransducerStaticWriter.h"

// Note: Le rôle de la classe TransducerStaticWriter
//       est donné à la page 12 du cahier de laboratoire

TransducerStaticWriter::TransducerStaticWriter(std::string const & text) 
	: Transducer(), mText{ text }
{
}

std::string TransducerStaticWriter::text() const 
{ 
	return mText; 
}

void TransducerStaticWriter::setText(std::string const & text)
{ 
	mText = text; 
}

std::string TransducerStaticWriter::transduce(symbol_t symbol)
{ 
	return mText; 
}