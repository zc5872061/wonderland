'''
Created on 18-12-2010

@author: Artur Mazurek

This script converts COLLADA files to a simple text file representation that is used by
the engine.

'''

import sys
from xml.dom import minidom
import os
from time import gmtime, strftime

class GeometryHolder:
    def __init__(self, xmlFile):
        self._geometries = []
        libGeometries = xmlFile.childNodes[0].getElementsByTagName\
            ("library_geometries")
        for geometry in libGeometries[0].getElementsByTagName("geometry"):
            self._geometries.append(Geometry(geometry))
            
    def getGeometries(self):
        return self._geometries
            
class Geometry:
    def __init__(self, geometryNode):
        self.name = ""
        self.id = ""
        self.indicesList = []
        self.verticesIds = []
        self.vertices = []
        self.normals = []
        self.uvs = []
        self.__initIndices(geometryNode)
        self.__loadData(geometryNode)
        
    def __initIndices(self, geometryNode):
        temp = set()
        polygons = geometryNode.getElementsByTagName("polygons")[0].getElementsByTagName("p")
        for p in polygons:
            values = p.firstChild.nodeValue.strip().split(" ")
            for i in range(3):
                vertex = (
                           values[i*3 + 0],
                           values[i*3 + 1],
                           values[i*3 + 2] 
                           )
                temp.add(vertex)
        #now we have a set of all, not doubled unique vertices
        #They should be modified into a list
        self.verticesIds = list(temp)
        #So, once we have a list of these triples we should create a list of vertices
        for p in polygons:
            values = p.firstChild.nodeValue.strip().split(" ")
            for i in range(3):
                vertex = (
                           values[i*3 + 0],
                           values[i*3 + 1],
                           values[i*3 + 2] 
                           )
                #self.indicesList.append(self.verticesIds.index(vertex))
                self.indicesList.append(vertex)
        
    def __loadData(self, geometryNode):
        self.id = geometryNode.attributes["id"].value
        self.name = geometryNode.attributes["name"].value
        print "Loading data for " + self.name
#        result.name = name
        sources = geometryNode.getElementsByTagName("mesh")[0].getElementsByTagName("source")
        for source in sources:
            sourceId = source.attributes["id"].value
            #print "    " + sourceId
            if sourceId == (self.id + "-Position"):
                self.vertices = self.__process(source, self.__createVectors3)
            elif sourceId == (self.id + "-Normal0"):
                #vertices and normals are mathematically identical
                self.normals = self.__process(source, self.__createVectors3)
            elif sourceId == (self.id + "-UV0"):
                self.uvs = self.__process(source, self.__createUV)
            else:
                raise Exception('Unknown source: ' + sourceId)
            
    def __process(self, source, methodPtr):
        vectorsArray = source.getElementsByTagName("float_array")[0].firstChild.nodeValue
        lines = vectorsArray.strip().split("\n")
        positions = []
        for line in lines:
            line = line.replace(",",".")
            vector = methodPtr(line)
            #vector.printDebug()
            positions.append(vector)
        return positions
    
    def __createVectors3(self, textLine):
        elements = textLine.split()
        if not len(elements) == 3:
            raise Exception('Wrong elements count when parsing vertices')
        return (elements[0], elements[1], elements[2])
    
    def __createUV(self, textLine):
        elements = textLine.split()
        if not len(elements) == 2:
            raise Exception('Wrong elements count when parsing vertices')
        return (elements[0], elements[1])       
        
class FileCreator:
    def __init__(self, rootPath, geometry): 
        self._file = open(rootPath + os.sep + geometry.name + ".dta", "w")
        self._geometry = geometry
        self._file.write("name:" + geometry.name + "\n")
        self._file.write("id:" + geometry.id + "\n")
        self._file.write("\n")
        self.__writeIndices()
        self._file.write("\n")
        self.__writeVertices()
        self._file.write("\n")
        self.__writeNormals()
        self._file.write("\n")
        self.__writeUvs()
        
    def __writeIndices(self):
        self._file.write("indices:" + str(len(self._geometry.indicesList)/3) + "\n")
        i = 1
        for index in self._geometry.indicesList:
            self._file.write(str(i-1))
            if i % 3 == 0 and not i == 0:
                self._file.write("\n")
            else:
                self._file.write(" ")
            i = i + 1
            
    def __writeVertices(self):
        self._file.write("vertices:" + str(len(self._geometry.indicesList)) + "\n")
        for index in self._geometry.indicesList:
            self._file.write( self._geometry.vertices[int(index[0])][0] + " " )
            self._file.write( self._geometry.vertices[int(index[0])][1] + " " )
            self._file.write( self._geometry.vertices[int(index[0])][2] + "\n" )
            #self.__writeElementWithOffset(self._geometry.vertices, index, 0)
            #vertexId = self._geometry.verticesIds[index]
            #print self._geometry.vertices[int(vertexId[0])]
            #print self._geometry.vertices[self._geometry.verticesIds.index[
        #print ""
        #for index in self._geometry.indicesList:
            #print index

            
    def __writeNormals(self):
        self._file.write("normals:" + str(len(self._geometry.indicesList)) + "\n")
        for index in self._geometry.indicesList:
            self._file.write( self._geometry.normals[int(index[1])][0] + " " )
            self._file.write( self._geometry.normals[int(index[1])][1] + " " )
            self._file.write( self._geometry.normals[int(index[1])][2] + "\n" )
 #           self.__writeElementWithOffset(self._geometry.normals, index, 1)
            
    def __writeUvs(self):
        self._file.write("uvs:" + str(len(self._geometry.indicesList)) + "\n")
        for index in self._geometry.indicesList:
            self._file.write( self._geometry.uvs[int(index[2])][0] + " " )
            self._file.write( self._geometry.uvs[int(index[2])][1] + "\n" )
  #          self.__writeElementWithOffset(self._geometry.uvs, index, 2)
            
    def __writeElementWithOffset(self, table, index, offset):
        values = table[int((self._geometry.verticesIds[int(index)])[int(offset)])]
        i = 1
        for x in values:
            self._file.write(x)
            if(i == len(values)):
                self._file.write("\n")
            else:
                self._file.write(" ")
            i = i + 1
              

if __name__ == '__main__':
    if not len(sys.argv) == 2:
        print 'Usage:'
        print 'ModelConverter <DAE file>'
        exit()
    xmlFile = minidom.parse(sys.argv[1])
    geometryHolder = GeometryHolder(xmlFile)
    
    directoryName = os.path.basename(sys.argv[1]) + "_" + strftime("%Y%m%d_%H%M%S", gmtime())
    os.mkdir(directoryName)
    
    for geometry in geometryHolder.getGeometries():
        FileCreator(directoryName, geometry)
        