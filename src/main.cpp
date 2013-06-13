﻿#include <QApplication>
#include "mainwindow.h"
#include "cyklgry.h"
#include "mistrzgry.h"
#include "plansza.h"
#include "oknonowejgry.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	int wynikParsowania = 0;
	CyklGry cykl(&wynikParsowania);
	Plansza plansza(&cykl);
	MistrzGry mistrz(&cykl);
	MainWindow okno;
	OknoNowejGry nowaGra;

	okno.setMistrzGry(&mistrz); //potem mainwindow pokazuje swoim komponentom komu mają zgłaszać zmiany/ informace
	okno.setPlansza(&plansza);

	//ustalanie kogo mistrz gry ma prosić o wyświetlanie informacji
	mistrz.setPanelAkcji(okno.getPanelAkcji());
	mistrz.setOknoGracza(okno.getOknoGracza());
	plansza.setObszarPlanszy(okno.getObszarPlanszy());

	cykl.setMistrzGry(&mistrz);
	cykl.setPlansza(&plansza);
	cykl.setMainWindow(&okno);
	mistrz.setPlansza(&plansza);
	plansza.setMistrzGry(&mistrz);
	nowaGra.setCyklGry(&cykl);
	nowaGra.setMainWindow(&okno);

	if (wynikParsowania != 0)
		return wynikParsowania;

	nowaGra.show();

	return a.exec();
}

