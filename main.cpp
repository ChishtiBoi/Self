#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 500;	// Maximum number of products in the inventory

// Function prototypes
void addProduct (string names[], double prices[], int quantities[],
		 int &count);
void viewInventory (const string names[], const double prices[],
		    const int quantities[], int count);
void updateInventory (string names[], int quantities[], int count);
void searchProduct (const string names[], const double prices[],
		    const int quantities[], int count);
void removeProduct (string names[], double prices[], int quantities[],
		    int &count);
void calculateTotalValue (const string names[], const double prices[],
			  const int quantities[], int count);

//Main body
int
main ()
{
  string productNames[MAX_PRODUCTS];
  double productPrices[MAX_PRODUCTS];
  int productQuantities[MAX_PRODUCTS];
  int productCount = 0;

  int choice;
  //loop to bring back to menu
  do
    {
      // Display menu
      cout << "---------------------------------------------\n";
      cout << "********Inventory Management System**********\n";
      cout << "_____________________________________________\n";
      cout << "1. Add Product\n";
      cout << "2. View Inventory\n";
      cout << "3. Update Inventory\n";
      cout << "4. Search for Product\n";
      cout << "5. Remove Product\n";
      cout << "6. Calculate Total Value\n";
      cout << "0. Exit\n";
      cout << "Enter your choice: ";
      cin >> choice;
      cout << "_____________________________________________\n";

      //choices for functions 
      switch (choice)
	{
	case 1:
	  addProduct (productNames, productPrices, productQuantities,
		      productCount);
	  break;
	case 2:
	  viewInventory (productNames, productPrices, productQuantities,
			 productCount);
	  break;
	case 3:
	  updateInventory (productNames, productQuantities, productCount);
	  break;
	case 4:
	  searchProduct (productNames, productPrices, productQuantities,
			 productCount);
	  break;
	case 5:
	  removeProduct (productNames, productPrices, productQuantities,
			 productCount);
	  break;
	case 6:
	  calculateTotalValue (productNames, productPrices, productQuantities,
			       productCount);
	  break;
	case 0:
	  cout << "********Exiting program.*********\n";
	  cout << "************Good Bye.************\n";
	  break;
	default:
	  cout << "Invalid choice. Please try again.\n";
	}

    }
  while (choice != 0);

  return 0;
}


//adding products to the inventory
void
addProduct (string names[], double prices[], int quantities[], int &count)
{
  if (count < MAX_PRODUCTS)
    {
      cout << "Enter product name: ";
      cin >> names[count];

      cout << "Enter product price: ";
      cin >> prices[count];

      cout << "Enter product quantity: ";
      cin >> quantities[count];

      count++;

      cout << "Product added successfully!\n";
    }
  else
    {
      cout << "Error: Maximum number of products reached.\n";
    }
}

//view products in inventory
void
viewInventory (const string names[], const double prices[],
	       const int quantities[], int count)
{
  if (count > 0)
    {
      cout << "Product List:\n";
      cout << "--------------------------------\n";
      cout << "Name\t\tPrice\tQuantity\n";
      cout << "--------------------------------\n";

      for (int i = 0; i < count; ++i)
	{
	  cout << names[i] << "\t\t" << prices[i] << "\t" << quantities[i] <<
	    endl;
	}

      cout << "--------------------------------\n";
    }
  else
    {
      cout << "No products in the inventory.\n";
    }
}

//update inventory
void
updateInventory (string names[], int quantities[], int count)
{
  if (count > 0)
    {
      string productName;
      cout << "Enter the name of the product to update: ";
      cin >> productName;

      // Search for the product
      int index = -1;
      for (int i = 0; i < count; ++i)
	{
	  if (names[i] == productName)
	    {
	      index = i;
	      break;
	    }
	}

      if (index != -1)
	{
	  int quantityChange;
	  cout << "Enter the quantity change (+/-): ";
	  cin >> quantityChange;

	  quantities[index] += quantityChange;

	  cout << "Quantity updated successfully!\n";
	}
      else
	{
	  cout << "Product not found.\n";
	}
    }
  else
    {
      cout << "No products in the inventory.\n";
    }
}

//Product search
void
searchProduct (const string names[], const double prices[],
	       const int quantities[], int count)
{
  if (count > 0)
    {
      string productName;
      cout << "Enter the name of the product to search: ";
      cin >> productName;

      // Search for the product
      int index = -1;
      for (int i = 0; i < count; ++i)
	{
	  if (names[i] == productName)
	    {
	      index = i;
	      break;
	    }
	}
      //Display of Product searched
      if (index != -1)
	{
	  cout << "Product found:\n";
	  cout << "Name: " << names[index] << endl;
	  cout << "Price: $" << prices[index] << endl;
	  cout << "Quantity: " << quantities[index] << endl;
	}
      else
	{
	  cout << "Product not found.\n";
	}
    }
  else
    {
      cout << "No products in the inventory.\n";
    }
}

//removing products from inventory
void
removeProduct (string names[], double prices[], int quantities[], int &count)
{
  if (count > 0)
    {
      string productName;
      cout << "Enter the name of the product to remove: ";
      cin >> productName;

      // Search for the product
      int index = -1;
      for (int i = 0; i < count; ++i)
	{
	  if (names[i] == productName)
	    {
	      index = i;
	      break;
	    }
	}

      if (index != -1)
	{
	  // Shift the elements to remove the product
	  for (int i = index; i < count - 1; ++i)
	    {
	      names[i] = names[i + 1];
	      prices[i] = prices[i + 1];
	      quantities[i] = quantities[i + 1];
	    }

	  count--;

	  cout << "Product removed successfully!\n";
	}
      else
	{
	  cout << "Product not found.\n";
	}
    }
  else
    {
      cout << "No products in the inventory. '-'\n";
    }
}

//valuation of inventory
void
calculateTotalValue (const string names[], const double prices[],
		     const int quantities[], int count)
{
  if (count > 0)
    {
      double totalValue = 0.0;

      for (int i = 0; i < count; ++i)
	{
	  totalValue += prices[i] * quantities[i];
	}

      cout << "Total inventory value: $" << totalValue << endl;
    }
  else
    {
      cout << "No products in the inventory. '-'\n";
    }
}
