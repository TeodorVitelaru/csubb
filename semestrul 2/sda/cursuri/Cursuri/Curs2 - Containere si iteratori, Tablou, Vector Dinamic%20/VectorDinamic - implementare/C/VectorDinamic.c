#include "VectorDinamic.h"
VectorDinamic* creeaza(int cp) {
	//aloca spatiu pentru vector
	//seteaza numarul de elemente
	return v;

void distruge(VectorDinamic* v) {

void redim(VectorDinamic* v) {
	//copiem vechile valori in noua zona
	for (i = 0; i < v->n; i++)
	//dublam capacitatea
	//eliberam vechea zona
	//vectorul indica spre noua zona

int dim(VectorDinamic* v) {

TElem element(VectorDinamic* v, int i) {

void adaugaSfarsit(VectorDinamic* v, TElem e) {
	v->e[(v->n)++] = e;

Iterator* creeazaIterator(VectorDinamic* v) {
	//varianta 2
void prim(Iterator* i) {
	//varianta 2
int valid(Iterator* i) {
}
TElem elementI(Iterator* i) {
	//varianta 2
void urmator(Iterator* i) {
void distrugeI(Iterator* i) {