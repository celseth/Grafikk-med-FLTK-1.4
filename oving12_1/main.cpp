#include <chrono>
#include <thread>
#include <memory>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl.H>
#include "utilities.h"
#include "Track.h"
#include "Vehicle.h"
#include "PlayerVehicle.h"
#include <Fl/fl_draw.H>
#include <iostream>

//Noe av koden i dette prosjektet tar utgangspunkt fra utdelt kode fra fagstaben i faget TDT4102 (utlities.cpp)


int main() {
	auto win = std::make_unique<Fl_Double_Window>(screenWidth, screenHeight, "NASCAR");
	win->color(FL_WHITE);

	// Instansier nye objekt mellom dei to etterfølgjande linjene.
	// -----------------------------------------------------------------------------
	auto t = new Track;
	Track T{};
	PlayerVehicle V{100,100,0,*t,88u};
	PlayerVehicle2 V2{100,200,0,T,218u};

	// -----------------------------------------------------------------------------

	win->end();
	win->show();

	auto nextDrawing = std::chrono::steady_clock::now();

	while (win->shown())
	{
		
		std::this_thread::sleep_until(nextDrawing);
		nextDrawing += std::chrono::microseconds(1'000'000 / 60);
		Fl::check();	// Handterar input
		Fl::redraw();	// Kallar draw
	}
}