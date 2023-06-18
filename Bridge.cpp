#include <iostream>
#include <vector>
#include <List>

using namespace std;


class Dispositivo {
public:
	virtual bool EstaHabilitado() = 0;
	virtual void Habilitar() = 0;
	virtual void Deshabilitar() = 0;
	virtual int ObtenerVolumen() = 0;
	virtual void EstablecerVolumen(int porcentaje) = 0;
};

class ControlRemoto {
protected:
	Dispositivo* dispositivo;
public:
	ControlRemoto(Dispositivo* dispositivo) :dispositivo(dispositivo) {
		dispositivo = dispositivo;
	}

	void alternarEncendido() {
		if (dispositivo->EstaHabilitado())
			dispositivo->Deshabilitar();
		else
			dispositivo->Habilitar();
	}
	void bajarVolumen() {
		dispositivo->EstablecerVolumen(dispositivo->ObtenerVolumen() - 10);
	}
	void subirVolumen() {
		dispositivo->EstablecerVolumen(dispositivo->ObtenerVolumen() + 10);
	}
};
class ControlRemotoAvanzado :public ControlRemoto {
public:
	ControlRemotoAvanzado(Dispositivo* dispositivo) :ControlRemoto(dispositivo) {
	}

	void silenciar() {
		dispositivo->EstablecerVolumen(0);
	}
};

class TV : public Dispositivo {
private:
	bool estado;
	int volumen;
	vector<string> canales;
	string marca;
	int canalActual;

public:
	TV(string marca) : estado(false), volumen(0), marca(marca), canalActual(0) {}

	bool EstaHabilitado() override {
		return estado;
	}
	void Habilitar() override {
		estado = true;
		cout << "La TV se esta encendido" << endl;
	}
	void Deshabilitar() override {
		estado = false;
		cout << "La TV esta apagado" << endl;
	}

	int ObtenerVolumen() override {
		return volumen;
	}

	void EstablecerVolumen(int porcentaje) override {
		volumen = porcentaje;
		cout << "El volumen de la TV se establecio en " << volumen << endl;
	}

	void AgregarCanal(string nombreCanal) {
		canales.push_back(nombreCanal);
	}

	void EstablecerCanal(int numeroCanal) {
		if (numeroCanal >= 0 && numeroCanal < canales.size()) {
			canalActual = numeroCanal;
			cout << "Se cambio al canal " << canales[canalActual] << " en el TV" << endl;
		}
		else {
			cout << "El canal especificado no es valido" << endl;
		}
	}
};

class Radio : public Dispositivo {
private:
	bool estado;
	int volumen;
	float canal;

public:
	Radio() {
		estado = false;
		volumen = 0;
		canal = 95.6;
	}

	bool EstaHabilitado() override {
		return estado;
	}

	void Habilitar() override {
		estado = true;
		cout << "La radio esta encendida" << endl;
	}

	void Deshabilitar() override {
		estado = false;
		cout << "La radio esta apagada" << endl;
	}

	int ObtenerVolumen() override {
		return volumen;
	}

	void EstablecerVolumen(int porcentaje) override {
		volumen = porcentaje;
		cout << "El volumen de la radio se establecio en " << volumen << endl;
	}

	void EstablecerCanal(float nuevoCanal) {
		canal = nuevoCanal;
		cout << "Se cambio al canal " << canal << " en la radio" << endl;
	}
};

class TVBox : public Dispositivo {
private:
	int volumen;
	string servicioactual;
	string peliculas;

public:
	TVBox(int v, string ser, string peliculas) {
		volumen = v;
		servicioactual = ser;
		peliculas = peliculas;

	}

	bool EstaHabilitado() override {
		return true;
	}

	void Habilitar() override {
		cout << "El TVBox esta encendido" << endl;
	}

	void Deshabilitar() override {
		cout << "El TVBox esta apagado" << endl;
	}

	int ObtenerVolumen() override {
		return volumen;
	}

	void EstablecerVolumen(int porcentaje) override {
		volumen = porcentaje;
		cout << "El volumen del TVBox se establecio en " << volumen << endl;
	}
};

int main() {
	TV tv("Sony");
	tv.AgregarCanal("Canal 1");
	tv.AgregarCanal("Canal 2");
	tv.AgregarCanal("Canal 3");

	Radio radio;

	TVBox tvBox(0,"You Tube","Proyecto x");

	ControlRemoto controlRemotoTV(&tv);
	ControlRemoto controlRemotoRadio(&radio);
	ControlRemoto controlRemotoTVBox(&tvBox);

	controlRemotoTV.alternarEncendido();
	controlRemotoTV.subirVolumen();
	
	controlRemotoRadio.alternarEncendido();
	controlRemotoRadio.subirVolumen();

	controlRemotoTVBox.alternarEncendido();
	controlRemotoTVBox.subirVolumen();
	
	return 0;
}
