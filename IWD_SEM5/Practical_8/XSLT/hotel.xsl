<?xml version="1.0"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
    <h1>Hotel list</h1>
    <table border="1">
      <tr bgcolor="#9acd32">
        <th>ID</th>
        <th>Name</th>
        <th>Star</th>
        <th>Facilities</th>
        <th>Address</th>
        <th>Distance</th>
        <th>Available</th>
      </tr>
      <xsl:for-each select="hotellist/hotel">
      <xsl:sort select="Star"/>
        <tr>
          <td bgcolor="#90F61"><xsl:value-of select="id"/></td>
          <td bgcolor="#F5EE1"><xsl:value-of select="Name"/></td>
          <td bgcolor="#29E7FB"><xsl:value-of select="Star"/></td>
          <td bgcolor="#D424F"><xsl:value-of select="Facilities"/></td>
          <td bgcolor="#7DBBF2"><xsl:value-of select="Address"/></td>
          <td bgcolor="#E74C3C"><xsl:value-of select="Distance"/></td>
          <td bgcolor="#F6BE1"><xsl:value-of select="Available"/></td>
        </tr>
      </xsl:for-each>
    </table>
  </body>
  </html>
</xsl:template>

</xsl:stylesheet>