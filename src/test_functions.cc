#include "../include/dispersion.h"
#include "../include/exploration.h"

int main() {
  // comprobar que se puede crear un objeto de la clase DispersionFunctionModule
  DispersionFunctionModule<int> dfm(10);
  // comprobar que se puede crear un objeto de la clase
  // DispersionFunctionPseudorandom
  DispersionFunctionPseudorandom<int> dfp(10);
  // comprobar que se puede crear un objeto de la clase DispersionFunctionSum
  DispersionFunctionSum<int> dfs(10);

  // comprobar que se puede crear un objeto de la clase
  // ExplorationFunctionLineal
  ExplorationFunctionLineal<int> efl;
  // comprobar que se puede crear un objeto de la clase
  // ExplorationFunctionDouble
  ExplorationFunctionDouble<int> efd(&dfm);
  // comprobar que se puede crear un objeto de la clase
  // ExplorationFunctionQuadratic
  ExplorationFunctionQuadratic<int> efq;
  // comprobar que se puede crear un objeto de la clase
  // ExplorationFunctionRedispersion
  ExplorationFunctionRedispersion<int> efr(&dfm);

  // comprobar los metodos de la clase DispersionFunctionModule
  std::cout << "DispersionFunctionModule" << std::endl;
  std::cout << "dfm(5): " << dfm(5) << std::endl;
  std::cout << "dfm(15): " << dfm(15) << std::endl;

  // comprobar los metodos de la clase DispersionFunctionPseudorandom
  std::cout << "DispersionFunctionPseudorandom" << std::endl;
  std::cout << "dfp(5): " << dfp(5) << std::endl;
  std::cout << "dfp(15): " << dfp(15) << std::endl;

  // comprobar los metodos de la clase DispersionFunctionSum
  std::cout << "DispersionFunctionSum" << std::endl;
  std::cout << "dfs(5): " << dfs(5) << std::endl;
  std::cout << "dfs(15): " << dfs(15) << std::endl;

  // comprobar los metodos de la clase ExplorationFunctionLineal
  std::cout << "ExplorationFunctionLineal" << std::endl;
  std::cout << "efl(5, 2): " << efl(5, 2) << std::endl;
  std::cout << "efl(15, 3): " << efl(15, 3) << std::endl;

  // comprobar los metodos de la clase ExplorationFunctionDouble
  std::cout << "ExplorationFunctionDouble" << std::endl;
  std::cout << "efd(7, 2): " << efd(7, 2) << std::endl;
  std::cout << "efd(12, 4): " << efd(12, 4) << std::endl;

  // comprobar los metodos de la clase ExplorationFunctionQuadratic
  std::cout << "ExplorationFunctionQuadratic" << std::endl;
  std::cout << "efq(3, 2): " << efq(3, 2) << std::endl;
  std::cout << "efq(8, 5): " << efq(8, 5) << std::endl;

  // comprobar los metodos de la clase ExplorationFunctionRedispersion
  std::cout << "ExplorationFunctionRedispersion" << std::endl;
  std::cout << "efr(4, 2): " << efr(4, 2) << std::endl;
  std::cout << "efr(10, 3): " << efr(10, 3) << std::endl;

  return 0;
}