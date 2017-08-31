# Gender Recognition
An application that detects face and recognizes gender and can be implemented for a variety of tasks such as market research and artificial intelligence. The final application uses a fisher face algorithm to extract the gender data from the face.

It was built using OpenCV in C++ with a QT GUI. The purpose of this implementation is a targeted marketing program, after every X seconds an advert is displayed dependent on the most common gender scanned. So in this scenario, as mine was the only face scanned, an advert for a male razor was displayed because the most common demographic after 10 seconds was male.

Gender is detected form the face and the confidence is calculated, if the confidence is below 0.5 then I programmed it to output no gender detected due to lack of certainty.

Here is an example: https://www.youtube.com/watch?v=MLKsH_wSRsU
