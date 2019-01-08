 #include <iostream>
#include <conio.h>
#include <string.h>
#include <iomanip>
using namespace std;
struct element
{
  char elements[200], elementname[118], actinades[50], lanthanades[50]; int atomicno[200], actinadesno[50], lanthanadesno[50]; float atomicmass[200], actinadesmass[50], lanthanadesmass[50];
};
int main()
{
  system("cls");
  string elementname[118] = {"Hydrogen","Helium","Lithium","Berylium","Boron","Carbon","Nitrogen","Oxygen","Flourine","Neon","Sodium","Magnesium","Aluminium","Silicon","Phosphorus","Sulphur","Chlorine","Argon","Potassium","Calcium","Scandium","Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt","Nickel","Copper","Zinc","Gallium","Germanium","Arsenic","Selenium","Bromine","Krypton","Rubidium","Strontium","Yttrium","Zirconium","Niobium","Molybdenum","Technetium","Ruthenium","Rhodium","Palladium","Silver","Cadmium","Indium","Tin","Antimony","Tellurium","Iodine","Xenon","Caesium","Barium","Lanthanum","Cerium","Praseodymium","Neodymium","Promethium","Samarium","Europium","Gadolinium","Terbium","Dysprosium","Holmium","Erbium","Thulium","Ytterbium","Lutetium","Hafnium","Tantalum","Tungsten","Rhenium","Osmium","Iridium","Platinum","Gold","Mercury","Thallium","Lead","Bismuth","Polonium","Astatine","Radon","Francium","Radium","Actinium","Thorium","Protactinium","Uranium","Neptunium","Plutonium","Americium","Curium","Berkelium","Californium","Einsteinium","Fermium","Mendelevium","Nobelium","Lawrencium","Rutherfordium","Dubnium","Seaborgium","Bohrium","Hassium","Meitnerium","Darmstadtium","Roentgenium","Copernicium","Nihonium","Flerovium","Moscovium","Livermorium","Tennissine","Oganesson"};
  string elements[200]={"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};/*,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,33,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118}*/

  int atomicno[118]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,33,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118};
  float atomicmass[200]={1.00,4.00,6.94,9.01,10.81,12.01,14.00,15.99,18.99,20.17,22.98,24.30,26.98,28.08,30.97,32.06,35.45,39.94,39.09,40.07,44.95,47.86,50.94,51.99,54.93,55.84,58.93,58.69,63.54,65.38,69.72,72.63,74.92,78.96,79.90,83.79,85.46,87.62,88.90,91.22,92.90,95.96,98.00,101.07,102.90,106.42,107.86,112.41,114.81,118.71,121.76,127.60,126.90,131.29,132.90,137.32,138.90,178.49,180.94,183.84,186.20,190.23,192.21,195.08,196.96,200.59,204.38,207.20,208.98,210.00,210.00,222.00,223.00,226.00,227.00,267.00,268.00,269.00,270.00,269.00,278.00,281.00,281.00,285.00,286.00,289.00,288.00,293.00,294.00,294.00};
  string actinades[50]={"Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu"};
  string lanthanades[50]={"Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};
  int actinadesno[50]={58,59,60,61,62,63,64,65,66,67,68,69,70,71};
  int lanthanadesno[50]={90,91,92,93,94,95,96,97,98,99,100,101,102,103};
  float actinadesmass[50]={140.11,140.90,144.24,145.00,150.36,151.96,157.25,158.92,162.50,164.93,167.25,168.93,173.05,174.96};
  float lanthanadesmass[50]={232.03,231.03,238.02,237.00,244.00,243.00,247.00,247.00,251.00,252.00,257.00,258.00,259.00,262.00};
  return 0;
}
