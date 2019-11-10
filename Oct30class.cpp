#include <iostream>
#include <fstream>
#include <string>
#include <vector>

  struct Estudiante {
    std::string name, id;
    std::vector<double> notas;
  };

  const int N_EST = 2;
  const int N_NOTAS = 4;

void setup_notas(Estudiante & e, int NNOTAS);
void print_course(std::vector<Estudiante> & curso, std::string fname);

  
  int main()
  {
    std::vector<Estudiante> curso1(N_EST); //Asignación de memoria dinámica para un arreglo de estudiantes (curso), cuya información se almacena como una estructura. 
    for (auto & est : curso1) { //El ampersand evita el uso de copias de datos al momento de ejecutar el bucle.  
      setup_notas(est, N_NOTAS); //Recordar: 'est' es un dato de tipo Estudiante. 
    }

    curso1[0].name = "Est1";
    curso1[0].id = "ID1";
    curso1[0].notas[0] = 4.5;
    curso1[0].notas[1] = 4.8;
    curso1[0].notas[2] = 4.1;
    curso1[0].notas[3] = 2.5;

    curso1[1].name = "Est2";
    curso1[1].id = "ID2";
    curso1[1].notas[0] = 2.5;
    curso1[1].notas[1] = 2.8;
    curso1[1].notas[2] = 2.1;
    curso1[1].notas[3] = 4.5;

    print_course(curso1, "curso.txt");
    
  return 0;
}

void setup_notas (Estudiante & e, int NNOTAS) //El ampersand se especifica en el argumento de la función y siginifica que trabaja directamente con los datos. 
{
  e.notas.resize(NNOTAS); //Asigna un número de filas al vector de notas de cada estudiante. 
}

void print_course (std::vector<Estudiante> & curso, std::string fname) //'fname' hace referencia al nombre del archivo, que en este caso se considera como parámetro.
{
  std::ofstream fout(fname); //apertura del 'ofstream'. // En 'fname' se introduce el nombre del archivo en el cual se quiere imprimir la información.
  fout << curso.size() << "\n"; //Corresponde al número de estudiantes que pertenecen al curso.
  fout << curso[0].notas.size() << "\n"; //Corresponde al número de notas por estudiante.
  for(const auto & est : curso) {
    fout << est.name << "\n";
    fout << est.id << "\n";
    for(const auto & grade : est.notas) {
      fout << grade << "\t";
    }
    fout << "\n"; //Cierre del 'ofstream'.
  }

  fout.close();
}

void read_course(std::vector<Estudiante> & curso, std::string fname) //Misma parámetros de la función 'print_course'.
{
  //Imprime información general
  std::ifstream fin(fname); //Apertura del 'ifstream' // En 'fname' se introduce el nombre del archivo del cual se quiere leer la información.
  int nest = 0, nnotas = 0; //Se definen primero las variables para que el programa pueda asignarles el valor que lee. 
  fin >> nest;
  fin >> nnotas;
  curso.resize(nest);
  for(auto & est : curso) { 
    setup_notas(est, nnotas); //Se trae a colación el arreglo para tener donde almacenar las notas.  
  }
  //Imprime información de cada estudiante
  for(auto & est : curso) {
    fin >> est.name;
    fin >> est.id;
    for(int ii = 0; ii < nnotas; ++ii) {
      fin >> est.notas[ii];
    }
  }

  fin.close(); //Cierre del 'ifstream'. 
  
}
