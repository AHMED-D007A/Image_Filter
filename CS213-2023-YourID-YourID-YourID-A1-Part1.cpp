#include <bits/stdc++.h>

using namespace std;

int main()
{
    string imageName;
    cout << "Enter the name of the image you want to edit: ";
    std::cin >> imageName;
    while (1)
    {
    char selection;
    string mergeImage, shrinkSelection;
    int x, y, z, w;
    
    cout << "Please select a filter to apply or 0 to exit:"
    << "\n1-Black & White Filter"
    << "\n2-Invert Filter"
    << "\n3-Merge Filter"
    << "\n4-Flip Image"
    << "\n5-Darken and Lighten Image"
    << "\n6-Rotate Image"
    << "\n7-Detect Image Edges"
    << "\n8-Enlarge Image"
    << "\n9-Shrink Image"
    << "\na-Mirror 1/2 Image"
    << "\nb-Shuffle Image"
    << "\nc-Blur Image"
    << "\nd-Crop Image"
    << "\ne-Skew Image Right"
    << "\nf-Skew Image Up"
    << "\ns-Save the image to a file"
    << "\n0-Exit\n";

    std::cin >> selection;

    if (selection == '0')
        break;
    switch (selection)
    {
    case '1':
        // Black and White Function
        break;
    case '2':
        // Invert Function
        break;
    case '3':
        // Merge Function
        cout << "Please enter name of image file to merge with: ";
        cin >> mergeImage;
        break;
    case '4':
        // Flip Function
        while (selection != 'h' || selection != 'v')
        {
        cout << "Flip (h)orizontally or (v)ertically?\n";
        cin >> selection;
        if (selection != 'h' || selection != 'v')
            cout << "Please make sure it's an available option.";
        }
        switch (selection)
        {
        case 'h':
            // Horizontal Flip
            break;
        
        case 'v':
            // Vertical Flip
            break;
        }
        break;
    case '5':
        // Darken and Lighten Function
        while (selection != 'd' || selection != 'l')
        {
        cout << "Do you want to (d)arken or (l)ighten?\n";
        cin >> selection;
        if (selection != 'd' || selection != 'l')
            cout << "Please make sure it's an available option.";
        }
        break;
    case '6':
        // Rotate Function
        break;
    case '7':
        // Detect Edges Function
        break;
    case '8':
        // Enlarge Function
        break;
    case '9':
        // Shrink Function
        break;
    case 'a':
        // Mirror Function
        break;
    case 'b':
        // Shuffle Function
        break;
    case 'c':
        // Blur Function
        break;
    case 'd':
        // Crop Function
        break;
    case 'e':
        // Skew Right Function
        break;
    case 'f':
        // Skew Up Function
        break;
    case 's':
        // Save Function
        break;
    default:
        cout << "Please make sure it's an available option.\n";
        break;
    }

    }


    return 0;
}