#include "Subgraph.h"

namespace DotWriter {

void Subgraph::Print(std::ostream& out, unsigned tabDepth) {
  std::string linePrefix = std::string(tabDepth*_tabIncrement, _tabCharacter);
  std::string titlePrefix =
    std::string((tabDepth-1)*_tabIncrement, _tabCharacter);

  out << titlePrefix << "subgraph " << GetId() << " {\n";

  if (_label.compare("") != 0) {
    if (_is_html_label) {
      _attributes.AddHtmlLabel(_label);
    } else {
      _attributes.AddCustomAttribute("label", _label);
    }
  }

  if (!_attributes.Empty()) {
    _attributes.Print(out, linePrefix);
    out << ";\n";
  }

  PrintNECS(out, tabDepth);

  out << titlePrefix << "}\n";
}

}  // namespace DotWriter
