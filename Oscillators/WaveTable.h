/*
==============================================================================
WaveTable.h
Created: 11 Feb 2018 11:19:46pm
Author:  Claudio
==============================================================================
*/

#pragma once

//We need <vector> inclusion because the wavetable is a vector of float values;
#include <vector>
#include <cmath>

#include "Utils.h"

/*
This class represent a wavetable, which, in poor words, is nothing than an array that can be read
For example, a wavetable representing a sawtooth wave will store values from -1 to +1
*/

#pragma once
class WaveTable
{
public:
	/*
	Constructor
	*/
	WaveTable();

	/*
	Constructor
	//When we create a wavetable for the first time, we can set it's length
	*/
	WaveTable(int length);

	/*
	Destructor
	*/
	~WaveTable();

	float readAt(int index) const {
		return content[index];
	}

	/*
	This method add a value to our content vector
	*/
	void addValue(float value) { content.push_back(value); }

	/*
	This method set a value to our content vector at the index
	*/
	void setValue(int index, float value) { content[index] = value; }

	/*
	This method returns the wavetable vector length
	*/
	int getLength() const { return content.size(); }

	/*
	_______________________________________ TODO __________________________________________________________________________________________
	This method will stretch the wavetable with the passed length
	Pratically the wavetable will remains the same but it will have a different length
	Example: I have this wavetable where content has 512 samples, and it's a sawtooth wave
	I call setLength(1024)
	The content will now be a vector of 1024 samples, but it will still be a sawtooth wave
	*/
	void setLength(int length);

	/*
	This method set the wavetable content to equal the passed vector
	*/
	void setContent(std::vector<float> contentVector) { content = contentVector; }

	/*
	This method simply return the wavetable content
	*/
	std::vector<float> getContent() const { return content; }

	/*
	This function will cut everything from the content vector which is above the passed range
	For example, if we have a wavetable that goes from -1.5 to +1.5 and we call "cutAboveRange(1.0f);" we will
	ensure that all the values of the wavetable will be between -1.0 and +1.0
	This means that this method replace with the passed value what it finds exceeding the range
	REQUIREMENT: the variable range must be positive
	*/
	void cutAboveRange(float range);

	/*
	This function will not affect the wavetable but will only read it values and will return the cutted version
	REQUIREMENT: the variable range must be positive
	*/
	std::vector<float> readCutAboveRange(float range);

	/*
	This function will invert every value of the wavetable
	By passing -1.0 we will have a completely inverted wavetable
	By passing 1.0 we will not affect the wavetable
	By passing 0.0 we will set the whole wavetable to be just 0 values
	By passing a value different than the one just explained, we will invert the wavetable by a value
	REQUIREMENT: the variable invert must be between -1.0 and 0.0
	*/
	void invertWavetable(float invert);

	/*
	This function will perform invertWavetable but will not affect the content
	REQUIREMENT: the variable invert must be between -1.0 and 0.0
	*/
	std::vector<float> readInvertWavetable(float invert);

	/*
	This function will scale the wavetable by the passing values
	If our wavetable content range is between -5 and 1
	And we call scaleWavetable(-1.0, 1.0)
	Thwe wavetable content will now be between -1 and 1 but it will contains always the same shape
	*/
	void scaleWavetable(float newMin, float newMax);

	/*
	This function will call scaleWavetable but will not affect the content
	*/
	std::vector<float> readScaleWavetable(float newMin, float newMax);

private:
	/*
	This variable is the one that will contain all the values of our wavetable
	*/
	std::vector<float> content;
};
