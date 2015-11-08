#include "Mesh.h"


Mesh::Mesh() : points(std::vector<Vec3<float>>()), faces(std::vector<Vec3<unsigned int>>()){};
Mesh::Mesh(std::vector<Vec3<float>> points_, std::vector<Vec3<unsigned int>> faces_, std::vector<Vec3<unsigned int>> facesTextures_, std::vector<Vec3<unsigned int>> facesNormales_, std::vector<Vec3<float>> textures_, std::vector<Vec3<float>> normales_, std::vector<Vec2<unsigned int>> arretes_)
	: points(points_), faces(faces_), textures(textures_), facesTextures(facesTextures_), facesNormales(facesNormales_), normales(normales_), arretes(arretes_)
{
	float max = 1.;
	colors = std::vector<float>();
	vertices = std::vector<float>();
	indices = std::vector<unsigned int>();

	for (unsigned int i = 0; i < points.size(); ++i)
	{
		max = std::fmaxf(max, std::fmaxf(std::fmaxf(std::abs(points[i].x), std::abs(points[i].y)), std::abs(points[i].z)));
	}

	pivot = Vec3<float>(0.f);
	for (unsigned int i = 0; i < points.size(); ++i)
	{
		points[i] = points[i] / max;
		pivot += points[i];

		colors.push_back(textures[0].x);
		colors.push_back(textures[0].y);
		colors.push_back(textures[0].z);

		vertices.push_back(points[i].x);
		vertices.push_back(points[i].y);
		vertices.push_back(points[i].z);
	}

	pivot = pivot / (float)points.size();

	//for (int i = 0; i < facesTextures.size(); i++)
	//{
	//	colors.push_back(Vec3<float>(textures[facesTextures[i].x].x, textures[facesTextures[i].x].y, textures[facesTextures[i].x].z));
	//	colors.push_back(Vec3<float>(textures[facesTextures[i].y].x, textures[facesTextures[i].y].y, textures[facesTextures[i].y].z));
	//	colors.push_back(Vec3<float>(textures[facesTextures[i].z].x, textures[facesTextures[i].z].y, textures[facesTextures[i].z].z));
	//}

	for (int i = 0; i < faces.size(); i++)
	{
		indices.push_back(faces[i].x);
		indices.push_back(faces[i].y);
		indices.push_back(faces[i].z);
	}
}

Mesh::Mesh(const Mesh & mesh)
	: points(mesh.points), faces(mesh.faces), textures(mesh.textures), facesTextures(mesh.facesTextures), facesNormales(mesh.facesNormales), normales(mesh.normales), 
	arretes(mesh.arretes), pivot(mesh.pivot), indices(mesh.indices), colors(mesh.colors), vertices(mesh.vertices) { };

std::vector<Vec3<float>> Mesh::getPoints() const
{
	return points;
}
std::vector<Vec3<unsigned int>> Mesh::getFaces() const
{
	return faces;
}

std::vector<Vec3<float>> Mesh::getTextures() const
{
	return textures;
}

std::vector<Vec3<float>> Mesh::getNormales() const
{
	return normales;
}

std::vector<Vec3<unsigned int>> Mesh::getFacesTextures() const
{
	return facesTextures;
}

std::vector<Vec3<unsigned int>> Mesh::getFacesNormales() const
{
	return facesNormales;
}

Vec3<float> Mesh::getCentreGravite() const
{
	return pivot;
}

std::vector<float> Mesh::getColors() const
{
	return colors;
}

std::vector<float> Mesh::getVertices() const
{
	return vertices;
}


std::vector<unsigned int> Mesh::getIndices() const
{
	return indices;
}

Mesh::~Mesh()
{
}
