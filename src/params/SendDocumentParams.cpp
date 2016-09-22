#include "params/SendDocumentParams.h"

using namespace telegram::params;

SendDocumentParams & SendDocumentParams::SetCaption(const std::string &caption)
{
    (*this)["caption"] = caption;
    return *this;
}