#include "Arduino.h"
#include "pitches.h"
#include "melodies.c"


#define SPEAKER_PIN 8
#define PIEZO_PIN 9


void playMelody(int melody[], int tempo[], int melody_size,
		float time_multiplier, int melody_pin) {
	for (int thisNote = 0; thisNote < melody_size; thisNote++) {
		// to calculate the note duration, take one second
		// divided by the note type.
		// e.g. quarter note = 1000 / 4, eighth note = 1000/8,
		// etc.
		int noteDuration = (1000 / tempo[thisNote]) * time_multiplier;
		tone(melody_pin, melody[thisNote], noteDuration);
		// to distinguish the notes, set a minimum
		// time between them.
		// the note's duration + 30% seems to
		// work well:
		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);
		// stop the tone playing:
		noTone(8);
	}
}

void setup() {
}

void loop() {
	playMelody(melody_mario, tempo_mario, sizeof(melody_mario) / sizeof(int),
		1.2, SPEAKER_PIN);
	delay(5000);
	playMelody(melody_mario_underworld, tempo_mario_underworld,
		sizeof(melody_mario_underworld) / sizeof(int),
		1.2, SPEAKER_PIN);
	delay(5000);
}
