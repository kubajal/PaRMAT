#include "Edge.hpp"


Edge::Edge(EdgeIndexType rec_src, EdgeIndexType rec_dst, int timestamp, int duration):
		src(rec_src), dst(rec_dst), meeting_timestamp(timestamp), meeting_duration(duration)
{}

Edge::Edge(const Edge &cSource) {
	src = cSource.src;
	dst = cSource.dst;
  meeting_duration = cSource.meeting_duration;
  meeting_timestamp = cSource.meeting_timestamp;
}

Edge& Edge::operator= (const Edge &cSource) {
	src = cSource.src;
	dst = cSource.dst;
  meeting_duration = cSource.meeting_duration;
  meeting_timestamp = cSource.meeting_timestamp;
	return *this;
}

bool Edge::selfEdge(){
	return ( src == dst );
}

bool operator< (const Edge& cR1, const Edge& cR2) {
	if( cR1.src < cR2.src )
		return true;
	else if( cR1.src > cR2.src )
		return false;
	else if( cR1.dst < cR2.dst )
		return true;
	else
		return false;
}

bool operator== (const Edge& cR1, const Edge& cR2) {
	return ( cR1.dst == cR2.dst && cR1.src == cR2.src);
}

std::ostream& operator<< (std::ostream &out, Edge &cEdge) {
	out << cEdge.src << "," << cEdge.dst << "," << cEdge.meeting_timestamp << "," << cEdge.meeting_duration << "\n";
	return out;
}